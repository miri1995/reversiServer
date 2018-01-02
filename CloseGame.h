//
// Created by michalbi on 23/12/17.
//

#ifndef REVERSISERVER_CLOSEGAME_H
#define REVERSISERVER_CLOSEGAME_H

#include"Command.h"
#include <iostream>

#include "Game.h"


class CloseGame: public Command{

public:
    virtual void execute(vector <string> args,int socket) {
        GameManager *gameManager;
        gameManager = GameManager::getInstance();
        vector<Game> games = gameManager->getGames();
        string name = args[0];
        gameManager->removeGame(name);
        return;
    }
};




#endif //REVERSISERVER_CLOSEGAME_H
