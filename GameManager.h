#ifndef REVERSISERVER_SINGLETON_H
#define REVERSISERVER_SINGLETON_H
#pragma once


#include <vector>
#include "Game.h"

class GameManager {
public:
/**********************************
       * name: get instance.
       * input:none
       * output: GameManager
**********************************/
    static GameManager *getInstance();
/**********************************
       * name: getGames.
       * input:none
       * output: the list of the games
**********************************/
    vector<Game> getGames();
/**********************************
       * name: addGame.
       * input:game
       * output: none
       * adds a game to the list of games.
**********************************/
    void addGame(Game game);
/**********************************
       * name: removeGame
       * input:name
       * output: none
       * removes a game from the list of games.
**********************************/
    void removeGame(string name);
/**********************************
       * name: gameIndex
       * input:name
       * output: index of a specific game in the list.
       * search a game in the list according to the given name.
**********************************/
    int gameIndex(string name);


private:
/**********************************
       * constructor
       * input:none
       * output: none.
**********************************/
    GameManager() {};
/**********************************
       *  copy constructor
       * input:gameManager other
       * output: none.
**********************************/
    GameManager(const GameManager &other);
/**********************************
       *  destructor
       * input:none
       * output: none.
**********************************/
    ~GameManager() {};
    static GameManager *instance;
    vector <Game> games;
};


#endif //REVERSISERVER_SINGLETON_H
