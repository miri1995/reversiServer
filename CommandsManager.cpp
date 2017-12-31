#include "CommandsManager.h"
#include "StartGame.h"
#include "JoinGame.h"
#include "PlayMove.h"
#include "CloseGame.h"


CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartGame();
    commandsMap["list_games"] = new ListGames;
    commandsMap["join"] = new JoinGame;
   // commandsMap["play <x> <y>"] = new PlayMove;
    commandsMap["close"] = new CloseGame;

// Add more commands...
}


void CommandsManager ::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj ->execute(args);
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