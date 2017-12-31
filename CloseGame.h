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
    virtual void execute(vector <string> args) {
        //erase game from list
        args.empty();
       return;
    }
};



#endif //REVERSISERVER_CLOSEGAME_H
