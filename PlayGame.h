#ifndef REVERSISERVER_PLAYGAME_H
#define REVERSISERVER_PLAYGAME_H


class PlayGame {
private:
    int clientSocket;
    int clientSocket2;
public:
    PlayGame(int clientSocket,int clientSocket2);
    void handleClient();
};


#endif //REVERSISERVER_PLAYGAME_H