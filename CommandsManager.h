#ifndef REVERSISERVER_COMMANDSMANAGER_H
#define REVERSISERVER_COMMANDSMANAGER_H
#include <map>
#include"Command.h"
#include "Server.h"

class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command, vector <string> args);
    //std::map getMap();
private:
    map<string, Command *> commandsMap;

};


#endif //REVERSISERVER_COMMANDSMANAGER_H
