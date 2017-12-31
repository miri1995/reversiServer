#ifndef REVERSISERVER_JOINGAME_H
#define REVERSISERVER_JOINGAME_H

#include"Command.h"
#include <iostream>
#include "Game.h"
#include "ListGames.h"
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>


class JoinGame: public Command {


public:
    virtual void execute(vector<string>args) {
        GameManager *gameManager;
        gameManager = GameManager::getInstance();
        vector<Game> games = gameManager->getGames();
        string name = args[0];
        int gameIndex = gameManager->gameIndex(name);
        if(gameIndex == -1){
            cout<<-1<<endl;
            return;
        }
        Game game = games.at(gameIndex);
        if(game.isJoinable()){
            game.setJoinable(false);// make sure that state of game in games member of game manager is false
        }

    }
};




#endif //REVERSISERVER_JOINGAME_H
