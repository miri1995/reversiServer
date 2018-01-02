#include "Game.h"


Game::Game(string name,int clientSocket,int clientSocket2){
    this->name = name;
    this->joinable = true;
    this->clientSocket = clientSocket;
    this->clientSocket2 = clientSocket2;
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

void Game:: setSocket2(int clientSocket){
    this->clientSocket2 = clientSocket;
}

int Game::getSocket1(){
    return this->clientSocket;
}
int Game::getSocket2(){
    return this->clientSocket2;
}