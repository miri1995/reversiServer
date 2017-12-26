//
// Created by michalbi on 23/12/17.
//

#ifndef REVERSISERVER_PLAYMOVE_H
#define REVERSISERVER_PLAYMOVE_H

#include"Command.h"
#include <iostream>

#include "Game.h"
#include "Server.h"

class PlayMove: public Command{

public:
    virtual void execute(Server server, int clientSocket,int clientSocket2) {
       server.handleClient(clientSocket,clientSocket2);
    }
};





#endif //REVERSISERVER_PLAYMOVE_H
