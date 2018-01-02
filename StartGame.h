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
    StartGame();
    virtual void execute(vector<string>args,int socket);



};


#endif //REVERSISERVER_PRINTCOMMAND_H

