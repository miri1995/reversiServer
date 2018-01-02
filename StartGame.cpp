//
// Created by michalbi on 01/01/18.
//
#include "StartGame.h"

StartGame::StartGame(){

}

 void StartGame::execute(vector<string>args,int socket) {
    GameManager *gameManager;
    gameManager = GameManager::getInstance();
    vector<Game> games = gameManager->getGames();
    string name = args[0];
    if(gameManager->gameIndex(name) != -1){
        cout<<-1<<endl;
        return;
    }
    //create new game
    Game game(name,socket,0);
    //add the game to the list
    gameManager->addGame(game);

}
