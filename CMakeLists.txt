cmake_minimum_required(VERSION 3.8)
project(reversiServer)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS -pthread)

set(SOURCE_FILES main.cpp Server.cpp Server.h Command.h CommandsManager.cpp CommandsManager.h StartGame.h Game.cpp Game.h ListGames.h JoinGame.h GameManager.cpp GameManager.h JoinGame.cpp StartGame.cpp PlayGame.cpp PlayGame.h ListGames.cpp Task.h ThreadPool.cpp ThreadPool.h)
add_executable(reversiServer ${SOURCE_FILES})