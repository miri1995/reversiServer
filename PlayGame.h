#ifndef REVERSISERVER_PLAYGAME_H
#define REVERSISERVER_PLAYGAME_H


#include "Game.h"

class PlayGame {
private:
    string name;
    int clientSocket;
    int clientSocket2;
    Game game;
public:
    /**********************************
    * constructor
    *
    * input: game
    * output: none
    **********************************/
    PlayGame(Game game);

    /****************************************************
    * handleClient: write and read the moves of the
    * client (in accordance to socket).
    * if to two players didn't have move -end game :
    * close the sockets.
    *
    * input: none
    * output: none
    ****************************************************/
    void handleClient();
};


#endif //REVERSISERVER_PLAYGAME_H