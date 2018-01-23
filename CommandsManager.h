#ifndef REVERSISERVER_COMMANDSMANAGER_H
#define REVERSISERVER_COMMANDSMANAGER_H
#include <map>
#include"Command.h"
#include "Server.h"

class CommandsManager {
public:
/**********************************
       * name: get instance.
       * input:none
       * output: command manager
**********************************/
    static CommandsManager *getInstance();
    /**********************************
          * name: executeCommand.
          * input:command,args,socket
          * output: none
          * execute the given command by the client according to the map.
   **********************************/
    void executeCommand(string command, vector <string> args,int socket = 0);


private:
    int socket;
/**********************************
       * constructor
       * input:none
       * output: none
**********************************/
    CommandsManager();
/**********************************
       * copy constructor
       * input:other command manager
       * output: none
**********************************/
    CommandsManager(const CommandsManager &other);
/**********************************
       * destructor
       * input:none
       * output: none
**********************************/
    ~CommandsManager();

    static CommandsManager* instance;
    static pthread_mutex_t lock;
    map<string,Command *> commandsMap;


};


#endif //REVERSISERVER_COMMANDSMANAGER_H