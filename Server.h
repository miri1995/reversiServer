#ifndef REVERSISERVER_SERVER_H
#define REVERSISERVER_SERVER_H


class Server {
private:
    int port;
    int serverSocket;
    void handleClient (int clientSocket,int clientSocket2);

public:
    Server(int port);
    void start();
    void stop();
};


#endif //REVERSISERVER_SERVER_H
