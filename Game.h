#ifndef REVERSISERVER_GAME_H
#define REVERSISERVER_GAME_H
#include <iostream>
#include <fstream>
using namespace std;

class Game {
private:
    string name;
    bool joinable;
public:
    Game(string name);
    string getName();
    void setJoinable(bool joinable);
    bool  isJoinable();


};


#endif //REVERSISERVER_GAME_H
