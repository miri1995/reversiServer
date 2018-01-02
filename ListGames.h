#ifndef REVERSISERVER_LISTGAMES_H
#define REVERSISERVER_LISTGAMES_H

#include"Command.h"


#include "Game.h"
#include "GameManager.h"

class ListGames: public Command{
//private:


public:
    ListGames();
    virtual void execute(vector<string>args,int socket=0) ;


};



#endif //REVERSISERVER_LISTGAMES_H
