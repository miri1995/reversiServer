#include <sys/socket.h>
#include "Server.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include "pthread.h"
using namespace std;

#define MAX_CONNECTED_CLIENTS 10
#define MAX_COMMAND_LEN 20


static void *acceptClients(void *);
static void *handleClient(void *);


Server::Server(int port) : port(port), serverSocket(0),serverThread(0){
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

    int thread = pthread_create(&serverThread, NULL,&acceptClients,(void*)serverSocket);
    if(thread){
        cout<<"Error: unable to create thread, "<< thread<< endl;
        exit(-1);
    }

}

static void *acceptClients(void* socket){
    long serverSocket = (long) socket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    while(true) {
        cout << "Waiting for client connections..." << endl;
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        pthread_t clientThread;
        int thread = pthread_create(&clientThread, NULL,&handleClient,(void*)clientSocket);
        if(thread){
            cout<<"Error: unable to create thread, "<< thread<< endl;
            exit(-1);
        }

    }

}


static void* handleClient(void *socket){
    int flag =0;
    long clientSocket = (long) socket;
    char commandStr[MAX_COMMAND_LEN];
    while(flag==0) {
        int n = read(clientSocket, commandStr, MAX_COMMAND_LEN);
        if (n == -1) {
            cout << "Error reading command" << endl;
            return NULL;
        }
        if (n == 0) {
            cout << "ERROR" << endl;
            return (void *) 0;
        }
        cout << "receive command: " << commandStr << endl;
        string str(commandStr);
        istringstream iss(str);
        string command;
        iss >> command;
        vector<string> args;
        while (iss) {
            string arg;
            iss >> arg;
            args.push_back(arg);
        }
        CommandsManager::getInstance()->executeCommand(command, args, clientSocket);
        if (command != "list_games") {
            flag = 1;
        }
    }

}



void Server::stop(){
    pthread_cancel(serverThread);
    close(serverSocket);
    close(port);
    cout<<"server stopped"<<endl;
}