#include "JoinGame.h"
#include "PlayGame.h"

JoinGame::JoinGame(){

}



void JoinGame:: execute(vector<string>args, int socket) {
    GameManager *gameManager;
    gameManager = GameManager::getInstance();
    vector<Game> games = gameManager->getGames();
    string name = args[0];//the name the client gives
    int gameIndex = gameManager->gameIndex(name);

    if(gameIndex == -1){//if the client chose a game that doesn't exist
        int error=-1;
        int message = write(socket, &error, sizeof(error));
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        return;
    }
    else{//the client chose a game that exists
        int error=0;
        int message = write(socket, &error, sizeof(error));
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }
    Game game = games.at(gameIndex);
    if(game.isJoinable()){
        game.setJoinable(false);//update the status of the game.
        game.setSocket2(socket);//set the socket of the client as socket 2 of the game.
        int socket1 = game.getSocket1();
        int socket2 = game.getSocket2();
        char x = '1';
        char o = '2';
        //write to player x that he is 1
        int message = write(socket1, &x, sizeof(x));//write socket1 x.
        if (message == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        //write to player o that he is 2
        int message2 = write(socket2, &o, sizeof(o));//write socket2 o.
        if (message2 == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
        Game sendGame = Game(game.getName(),socket1,socket);

        //remove the game from the list
        gameManager->removeGame(game.getName());
        PlayGame playGame(sendGame);//send the game to the class which is responsible to the
        //course of the game.
        playGame.handleClient();
    }

}