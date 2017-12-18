#ifndef REVERSISERVER_SERVER_H
#define REVERSISERVER_SERVER_H


class Server {
private:
    int port;
    int serverSocket;
    void handleClient (int clientSocket,int clientSocket2);

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