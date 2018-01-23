#ifndef REVERSISERVER_SERVER_H
#define REVERSISERVER_SERVER_H

#include <vector>
#include "Game.h"
#include "CommandsManager.h"
#include "GameManager.h"

class Server {
private:
    int port;
    int serverSocket;
    pthread_t serverThread;


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
    void stop();


};


#endif //REVERSISERVER_SERVER_H