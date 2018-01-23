#ifndef REVERSISERVER_GAME_H
#define REVERSISERVER_GAME_H
#include <iostream>
#include <fstream>
using namespace std;

class Game {
private:
    string name;
    bool joinable;
    int clientSocket;
    int clientSocket2;
public:
/**********************************
       * constructor
       * input:name,clientSocket,clientSocket2
       * output: none
**********************************/
    Game(string name,int clientSocket,int clientSocket2);
/**********************************
       * name: getName
       * input:none
       * output: the name of the game
**********************************/
    string getName();
/**********************************
       * name: setJoinable
       * input:joinable
       * output: none
       * set the game status(if the client can join the game or not).
**********************************/
    void setJoinable(bool joinable);
/**********************************
       * name: isJoinable
       * input:none
       * output: false if the client can't join the game,
         true if the client can join the game.
**********************************/
    bool  isJoinable();
/**********************************
       * name: setSocket2
       * input:clientSocket
       * output:none
       * set's the other opponent socket
 **********************************/
    void setSocket2(int clientSocket);
/**********************************
       * name: getSocket1
       * input:none
       * output:socket1
**********************************/
    int getSocket1();
/**********************************
       * name: getSocket2
       * input:none
       * output:socket2
**********************************/
    int getSocket2();


};


#endif //REVERSISERVER_GAME_H