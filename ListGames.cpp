#include <unistd.h>
#include "ListGames.h"

ListGames::ListGames(){

}


void ListGames:: execute(vector<string>args,int socket) {
    GameManager *gameManager;
    gameManager = GameManager::getInstance();
    vector<Game> games = gameManager->getGames();
    string nameOfGame;
    for(int i=0;i<games.size();i++) {
        if (games.at(i).isJoinable()) {
            nameOfGame.append(games.at(i).getName());
            nameOfGame.append(" , ");
        }
    }
    //write the list of games to the client.
    int n = write(socket, nameOfGame.c_str(), nameOfGame.length() + 1);
    if (n == -1) {
        throw "Error writing row to socket";
    }

}