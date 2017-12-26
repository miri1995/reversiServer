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
private:
    ListGames list;

public:
    virtual void execute(vector<string>name) {
        int i;

        for(i=0;i<list.returnList().size();i++){
            if(list.returnList().at(i).getName()==name[1]){
                //לעשות אקספט לסוקט השני, להוריד מהרשימה את המחשק הרלוונטי ולחלק 1,2
              list.deleteFromList(i);
                return;
            }
        }
        if(list.returnList().at(i).getName()!=name[1]){
            cout<<"no such game"<<endl;
        }


    }
};




#endif //REVERSISERVER_JOINGAME_H
