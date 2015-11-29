// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: level.h
// ====================================================
//

#ifndef level_hpp
#define level_hpp

#include "player.h"

class Level{
public:
    ~Level();
    virtual Player* createPlayer(char);
};

#endif /* level_hpp */
