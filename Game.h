//
// Created by michalbi on 22/12/17.
//

#ifndef REVERSISERVER_GAME_H
#define REVERSISERVER_GAME_H
#include <iostream>
#include <fstream>
using namespace std;

class Game {
private:
    string name;
   // int clientSocket;
public:
    Game(string name);
    string getName();


};


#endif //REVERSISERVER_GAME_H
