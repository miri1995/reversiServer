#ifndef REVERSISERVER_COMMANDSMANAGER_H
#define REVERSISERVER_COMMANDSMANAGER_H
#include <map>
#include"Command.h"
#include "Server.h"

class CommandsManager {
public:
    static CommandsManager *getInstance();
    void executeCommand(string command, vector <string> args,int socket = 0);

private:
    CommandsManager();
    CommandsManager(const CommandsManager &other);
    ~CommandsManager();
   static CommandsManager* instance;
    static pthread_mutex_t lock;
    map<string,Command *> commandsMap;

};


#endif //REVERSISERVER_COMMANDSMANAGER_H
