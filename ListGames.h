//
// Created by michalbi on 23/12/17.
//

#ifndef REVERSISERVER_LISTGAMES_H
#define REVERSISERVER_LISTGAMES_H

#include"Command.h"


#include "Game.h"

class ListGames: public Command{
private:
    vector <Game> games;

public:

    virtual void execute(vector<string>args) {
      //for(i)

    }
    void deleteFromList(int i){

        games.erase(games.begin()+i);
    }
    void addToList(Game game){

        games.push_back(game);
    }

    vector <Game> returnList(){
        return games;
    }

};



#endif //REVERSISERVER_LISTGAMES_H
