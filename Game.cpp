#include "Game.h"


Game::Game(string name){
    this->name = name;
    this->joinable = true;
}

string Game::getName(){
    return this->name;
}

void Game::setJoinable(bool canJoin){
    this->joinable = canJoin;
}

bool Game::isJoinable() {
    return this->joinable;
};