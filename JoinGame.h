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
/**********************************
   * constructor
   * input: none
   * output: none
**********************************/
    JoinGame();
    virtual void execute(vector<string>args, int socket);
};




#endif //REVERSISERVER_JOINGAME_H
