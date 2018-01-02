#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager *GameManager::instance = 0;

GameManager *GameManager::getInstance()
{
    if (instance == 0)
    {
        instance = new GameManager;
    }
    return instance;
}



/*GameManager::~GameManager() {

    for (int i=0; i<games.size();i++) {
        delete games.at(i);
    }
}*/

vector<Game> GameManager:: getGames(){
    return games;
}

void GameManager::addGame(Game game){
    games.push_back(game);
}

void GameManager:: removeGame(string name){
    int gameIndex = -1;
    for(int i=0;i<games.size();i++){
        if(games.at(i).getName()==name){
            gameIndex = i;
            break;
        }
    }
    if(gameIndex!=-1){
        games.erase(games.begin() + gameIndex);
    }
}

int GameManager:: gameIndex(string name){
    for(int i=0;i<games.size();i++) {
        if (games.at(i).getName() == name) {
            return i;
        }
    }
    return -1;
}


bool GameManager::ifGameCreated(string name) {
    vector<Game> games = getGames();
    for (int i = 0; i < games.size(); i++) {
        if (name == games.at(i).getName()) {
            return true;
        }
    }
    return false;
}