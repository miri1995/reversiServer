#include "CommandsManager.h"
#include "CreateGame.h"
#include "JoinGame.h"
#include "PlayMove.h"
#include "CloseGame.h"


CommandsManager::CommandsManager() {
    commandsMap["start <name>"] = new CreateGame();
    commandsMap["list_games"] = new ListGames;
    commandsMap["join <name>"] = new JoinGame;
    commandsMap["play <x> <y>"] = new PlayMove;
    commandsMap["close <name>"] = new CloseGame;

// Add more commands...
}


void CommandsManager ::executeCommand(string command, void* arg) {
    Command *commandObj = commandsMap[command];
    commandObj ->execute(arg);
}


CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it ->second;
    }

    /* map CommandsManager::getMap() {
         return commandsMap;
     } */
}