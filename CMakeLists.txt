cmake_minimum_required(VERSION 3.8)
project(reversiServer)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Server.cpp Server.h Command.h CommandsManager.cpp CommandsManager.h CreateGame.h Game.cpp Game.h ListGames.h JoinGame.h PlayMove.h CloseGame.h WhichCommend.h)
add_executable(reversiServer ${SOURCE_FILES})