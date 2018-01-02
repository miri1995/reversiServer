#ifndef REVERSISERVER_GAME_H
#define REVERSISERVER_GAME_H
#include <iostream>
#include <fstream>
using namespace std;

class Game {
private:
    string name;
    bool joinable;
    int clientSocket;
    int clientSocket2;
public:
    Game(string name,int clientSocket,int clientSocket2);
    string getName();
    void setJoinable(bool joinable);
    bool  isJoinable();

    void setSocket2(int clientSocket);
    int getSocket1();
    int getSocket2();


};


#endif //REVERSISERVER_GAME_H
