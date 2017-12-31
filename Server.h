#ifndef REVERSISERVER_SERVER_H
#define REVERSISERVER_SERVER_H

#include <vector>
#include "Game.h"
#include "CommandsManager.h"
#include "GameManager.h"
class CommandsManager;
class Server {
private:
    int port;
    int serverSocket;
    vector<pthread_t> clientThreads;
    pthread_mutex_t gamesMutex;
    CommandsManager commandsManager;
    GameManager *gameManager;



   // void handleClient (int clientSocket,int clientSocket2);

public:
    /**********************************
    * constructor
    *
    * input: port
    * output: none
    **********************************/
    Server(int port);

    /**********************************
    * name: start
     *      connect to 2 sockets (2 clients)
     *      and go to handleClient function.
    *
    * input: none
    * output: none
    **********************************/
    void start();

    /**********************************
    * name: stop
     *      close the server socket.
    *
    * input: none
    * output: none
    **********************************/

    //void handleClient (int clientSocket);
     void* handleClient(void *tArgs);
    int getClientSocket();
   // void start(int clientSocket);
   bool ifGameCreated(string name);

};


#endif //REVERSISERVER_SERVER_H