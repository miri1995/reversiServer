#ifndef REVERSISERVER_LISTGAMES_H
#define REVERSISERVER_LISTGAMES_H

#include"Command.h"


#include "Game.h"
#include "GameManager.h"

class ListGames: public Command{
//private:


public:
/**********************************
   * constructor
   * input: none
   * output: none
**********************************/
    ListGames();
    virtual void execute(vector<string>args,int socket=0) ;


};



#endif //REVERSISERVER_LISTGAMES_H
