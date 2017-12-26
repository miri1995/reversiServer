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


class CreateGame {
private:
   // vector<Game> games;
    ListGames list;

public:
    virtual void execute(vector<string>name) {

        for(int i=0;i<list.returnList().size();i++) {
            if (list.returnList().at(i).getName() == name[1]) {
               break;
                }

        }

        //create new game
        Game game(name[1]);
        //add the game to the list
        list.addToList(game);


    }
};


#endif //REVERSISERVER_PRINTCOMMAND_H

