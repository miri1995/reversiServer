#ifndef REVERSISERVER_SINGLETON_H
#define REVERSISERVER_SINGLETON_H
#pragma once


#include <vector>
#include "Game.h"

class GameManager {
public:
    static GameManager *getInstance();
    vector<Game> getGames();
    void addGame(Game game);
    void removeGame(string name);
    int gameIndex(string name);



private:
    GameManager() {}; // Private c'tor
    GameManager(const GameManager &other); // Private copy c'tor
    ~GameManager() {};
    static GameManager *instance;
    vector <Game> games;
};


#endif //REVERSISERVER_SINGLETON_H
