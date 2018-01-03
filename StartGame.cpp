#include "StartGame.h"

StartGame::StartGame(){

}

void StartGame::execute(vector<string>args,int socket) {
    GameManager *gameManager;
    gameManager = GameManager::getInstance();
    vector<Game> games = gameManager->getGames();
    string name = args[0];
    //if the game in the list- d'ont create new game- write to client -1
    if(gameManager->gameIndex(name) != -1){
        int error=-1;
        int message = write(socket, &error, sizeof(error));
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        return;
    }
        //if the game is not in the list- create new game- write to client 0
    else{
        int error=0;
        int message = write(socket, &error, sizeof(error));
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
    //create new game
    Game game(name,socket,0);
    //add the game to the list
    gameManager->addGame(game);

}