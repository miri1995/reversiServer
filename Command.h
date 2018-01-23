
#ifndef REVERSISERVER_COMMAND_H
#define REVERSISERVER_COMMAND_H

#include <vector>
#include <string>
#include "Game.h"
using namespace std;


class Command {
public:
/**********************************
       * name: execute the client's command.
       * input:none
       * output: none
**********************************/
    virtual void execute(vector<string> args,int socket = 0) =0;
    /**********************************
    *destructor.
    * input: port
    * output: none
**********************************/
    virtual~Command() {};
};


#endif //REVERSISERVER_COMMAND_H