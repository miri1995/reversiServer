#ifndef REVERSISERVER_SERVER_H
#define REVERSISERVER_SERVER_H

#include <vector>
#include "Game.h"
#include "CommandsManager.h"

class Server {
private:
    int port;
    int serverSocket;
   // vector<Game> games;
    //CommandsManager manager;

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

    void handleClient (int clientSocket,int clientSocket2);
   // void start(int clientSocket);

};


#endif //REVERSISERVER_SERVER_H