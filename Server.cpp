#include <sys/socket.h>
#include "Server.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include "pthread.h"
using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server(int port) : port(port), serverSocket(0){
    cout << "Server" << endl;
    gameManager = GameManager::getInstance();


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

    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void*(*))
    while(true) {
        cout << "Waiting for client connections..." << endl;
         int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        cout << "Waiting for other player to join..." << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        cout << "Waiting for client connections..." << endl;

        /*int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
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
        close(clientSocket2);*/

        pthread_t clientThread;
        int thread = pthread_create(&clientThread, NULL,handleClient,(void*)clientSocket);
        if(thread){
            cout<<"Error: unable to create thread, "<< thread<< endl;
            exit(-1);

         }

        this->clientThreads.push_back(clientThread);
        pthread_join(clientThread, NULL);//TODO check if need to use join and how
        close(clientSocket);
    }

}

 void*  Server:: handleClient(void *tArgs) {
     long clientSocket = (long) tArgs;
    string command;
    string name;
    string str;

    while (true) {

        while(str.compare('\0')){
            int n = read(clientSocket, &str, sizeof(str));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return (void*)-1;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return (void*)0;
            }
        }

        //split the client input
        int i = 0;
        const char* str_c = str.c_str();
        string arr[strlen(str_c)];
        stringstream ssin(str);
        while (ssin.good() && i < strlen(str_c)){
            ssin >> arr[i];
            ++i;
        }
        command = arr[0]; //the command
        name = arr[1]; //the name of the game
        vector<string> args;
        args.push_back(name);

         pthread_mutex_trylock(&this->gamesMutex);
        commandsManager.executeCommand(command,args);
        pthread_mutex_unlock(&this->gamesMutex);

        // in case command is start check if the game was created or not
        // and set the new game accordingly
        if (command == "start" && !ifGameCreated(name)) {
            Game game = Game(name);
            pthread_mutex_trylock(&this->gamesMutex);
            if(!game.isJoinable()){ // get "updated" game from game manager and check if not joinable (game should start)
                char x = '1';
                //write to player x that he is 1
                int message = write(clientSocket, &x, sizeof(x));
                if (message == -1) {
                    cout << "Error writing to socket" << endl;
                    return (void*)-1;
                }
            }
            pthread_mutex_unlock(&this->gamesMutex);
        }
        else if(command == "join"){
            pthread_mutex_trylock(&this->gamesMutex);
            char o = '2';
            int message = write(clientSocket, &o, sizeof(o));
            if (message == -1) {
                cout << "Error writing to socket" << endl;
                return (void*)-1;
            }
            pthread_mutex_unlock(&this->gamesMutex);
        }
    }
}


bool Server::ifGameCreated(string name) {
    vector<Game> games = gameManager->getGames();
    for (int i = 0; i < games.size(); i++) {
        if (name == games.at(i).getName()) {
            Game game = Game(name);
            return true;
        }
    }
    return false;
}





/*
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
}*/


/*string str;
       int n = read(clientSocket,&str,sizeof(str));
       if (n == -1) {
           cout << "Error reading arg1" << endl;
           return;
       }
       if (n == 0) {
           cout << "Client disconnected" << endl;
           return;
       }*/

/* string str1;
       n = read(clientSocket,&str1,sizeof(str1));
       if (n == -1) {
           cout << "Error reading arg1" << endl;
           return;
       }
       if (n == 0) {
           cout << "Client disconnected" << endl;
           return;
       }*/
/*int Server::getClientSocket(){
    return this->clientSocket;
}*/