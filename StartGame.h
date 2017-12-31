#ifndef REVERSISERVER_PRINTCOMMAND_H
#define REVERSISERVER_PRINTCOMMAND_H

#include"Command.h"
#include <iostream>
#include <sys/socket.h>
#include "Server.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "Game.h"
#include "ListGames.h"


class StartGame: public Command {


public:
    virtual void execute(vector<string>args) {
        GameManager *gameManager;
        gameManager = GameManager::getInstance();
        vector<Game> games = gameManager->getGames();
        string name = args[0];
        if(gameManager->gameIndex(name) != -1){
            cout<<-1<<endl;
         return;
        }
        //create new game
        Game game(name);
        //add the game to the list
        gameManager->addGame(game);

    }



};


#endif //REVERSISERVER_PRINTCOMMAND_H

