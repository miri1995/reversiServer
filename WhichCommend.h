//
// Created by michalbi on 23/12/17.
//

#ifndef REVERSISERVER_WHICHCOMMEND_H
#define REVERSISERVER_WHICHCOMMEND_H
#include"Command.h"
#include "CloseGame.h"
#include "StartGame.h"
#include "JoinGame.h"
#include "PlayMove.h"
#include "ListGames.h"

class WhichCommand: public Command{
public:
     virtual void execute1(int arg){
         if(arg==1){
             CloseGame closeGame;
             closeGame.execute();
         }
         else if (arg ==2){
             StartGame createGame;
             ListGames listGames;
             int serverSocket;
             struct sockaddr_in clientAddress;
             socklen_t clientAddressLen;
             string name;
             createGame.execute(listGames,serverSocket, clientAddress,clientAddressLen,name);
         }
         else if(arg==3){
             int clientSocket;
             Server server(int port);
             ListGames list;
             char* name;
             int serverSocket;
             struct sockaddr_in clientAddress;
             socklen_t clientAddressLen;
             JoinGame joinGame;
             joinGame.execute(clientSocket,server(8000),list,name,serverSocket,clientAddress,clientAddressLen);
         } else if (arg==4){
             Server server(int port);
             PlayMove playMove;
             int clientSocket;
             int clientSocket2;
             playMove.execute(server(8000),clientSocket,clientSocket2);
         }
     }
    virtual vector<Game> execute2(){
        ListGames listGames;
        listGames.execute();
    }

};




#endif //REVERSISERVER_WHICHCOMMEND_H
