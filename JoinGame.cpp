//
// Created by michalbi on 01/01/18.
//

#include "JoinGame.h"
#include "PlayGame.h"

JoinGame::JoinGame(){

}



 void JoinGame:: execute(vector<string>args, int socket) {
    GameManager *gameManager;
    gameManager = GameManager::getInstance();
    vector<Game> games = gameManager->getGames();
    string name = args[0];
    int gameIndex = gameManager->gameIndex(name);
    if(gameIndex == -1){
        cout<<-1<<endl;
        return;
    }
    Game game = games.at(gameIndex);
    if(game.isJoinable()){
        game.setJoinable(false);// make sure that state of game in games member of game manager is false
        game.setSocket2(socket);
        int socket1 = game.getSocket1();
        int socket2 = game.getSocket2();
        char x = '1';
        char o = '2';
        //write to player x that he is 1
        int message = write(socket1, &x, sizeof(x));
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        //write to player o that he is 2
        int message2 = write(socket2, &o, sizeof(o));
        if (message2 == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        PlayGame playGame(socket1,socket2);
        playGame.handleClient();
    }

}