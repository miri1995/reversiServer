//
// Created by michalbi on 01/01/18.
//
#include "ListGames.h"

ListGames::ListGames(){

}


void ListGames:: execute(vector<string>args,int socket) {
    GameManager *gameManager;
    gameManager = GameManager::getInstance();
    vector<Game> games = gameManager->getGames();
    for(int i=0;i<games.size();i++)
        if (games.at(i).isJoinable()) {
            cout << games.at(i).getName() << ", " << endl;
        }
}