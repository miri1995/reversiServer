

#ifndef REVERSISERVER_SERVER_H
#define REVERSISERVER_SERVER_H


class Server {
private:
    int port;
    int serverSocket;
    void handleClient (int clientSocket);
    int calc (int arg1, const char op, int arg2) const;
public:
    Server(int port);
    void start();
    void stop();
};


#endif //REVERSISERVER_SERVER_H
