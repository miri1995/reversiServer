#ifndef REVERSISERVER_LISTGAMES_H
#define REVERSISERVER_LISTGAMES_H

#include"Command.h"


#include "Game.h"
#include "GameManager.h"

class ListGames: public Command{
//private:


public:

    virtual void execute(vector<string>args) {
        GameManager *gameManager;
        gameManager = GameManager::getInstance();
        vector<Game> games = gameManager->getGames();
        for(int i=0;i<games.size();i++)
            if (games.at(i).isJoinable()) {
                cout << games.at(i).getName() << ", " << endl;
            }
    }

};



#endif //REVERSISERVER_LISTGAMES_H
