#include <unistd.h>
#include <sstream>
#include <iostream>

using namespace std;
#include "PlayGame.h"

PlayGame::PlayGame(int clientSocket,int clientSocket2) {
    this->clientSocket=clientSocket;
    this->clientSocket2=clientSocket2;
}

void PlayGame::handleClient() {
    int arg1, arg2;
    int player = 1;


    while (true) {
        //if the player 1(=x) play
        if (player % 2 == 1) {
            // Read new choice arguments
            int n = read(clientSocket, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }
            n = read(clientSocket, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error reading arg2" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }

            cout << "Got Choose: " << arg1 << "," << arg2 << endl;

            // Write the choose back to the client
            n = write(clientSocket2, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error writing to socket1" << endl;
                return;
            }
            n = write(clientSocket2, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error writing to socket3" << endl;
                return;
            }

        }
            //if the player 2(=o) play
        else {
            // Read new choice arguments
            int n = read(clientSocket2, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }
            n = read(clientSocket2, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error reading arg2" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }

            cout << "Got Choose: " << arg1 << "," << arg2 << endl;


            // Write the choose back to the client
            n = write(clientSocket, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error writing to socket1" << endl;
                return;
            }
            n = write(clientSocket, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error writing to socket3" << endl;
                return;
            }

        }
        player++;
        //if to two players didn't have move -end game
        if (arg1 == -2 && arg2 == -2) {
            cout<<"Game over"<<endl;
            return;
        }
    }//end while
}
