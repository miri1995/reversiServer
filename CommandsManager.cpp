#include "CommandsManager.h"
#include "StartGame.h"
#include "JoinGame.h"





CommandsManager* CommandsManager::instance = 0;
pthread_mutex_t CommandsManager::lock;

CommandsManager* CommandsManager::getInstance() {
    if(instance == 0){
        pthread_mutex_lock(&lock);
        if(instance == 0){
            instance = new CommandsManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}



CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartGame();
    commandsMap["list_games"] = new ListGames;
    commandsMap["join"] = new JoinGame;

    //commandsMap["close"] = new CloseGame;

// Add more commands...
}


void CommandsManager ::executeCommand(string command, vector<string> args, int socket) {
    Command *commandObj = commandsMap[command];
    commandObj ->execute(args,socket);
}


CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }
}

