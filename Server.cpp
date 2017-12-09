#include <sys/socket.h>
#include "Server.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10

Server::Server(int port) : port(port), serverSocket(0){
    cout << "Server" << endl;
}

void Server::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if(bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))==-1){
        throw "Error on binding";
    }

    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    while(true) {
        cout << "Waiting for client connections..." << endl;
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        cout << "Waiting for other player to join..." << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        cout << "Waiting for client connections..." << endl;
        int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket2 == -1) {
            throw "Error on accept";
        }
        char x = '1';
        char o = '2';
        //write to player x that he is 1
        int message = write(clientSocket, &x, sizeof(x));
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        //write to player o that he is 2
        int message2 = write(clientSocket2, &o, sizeof(o));
        if (message2 == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }

        handleClient(clientSocket, clientSocket2);
        close(clientSocket);
        close(clientSocket2);
        cout<<"hh"<<endl;
    }

}


void Server::handleClient(int clientSocket,int clientSocket2) {
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
            stop();
            cout<<"Game over"<<endl;
        }
    }//end while
}


void Server::stop() {
    close(serverSocket);
}