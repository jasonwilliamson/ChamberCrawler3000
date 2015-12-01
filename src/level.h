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
#include "constants.h"
#include "cell.h"

class Level{
public:
    virtual ~Level();
    virtual void initLevel(Cell *cellGrid[HEIGHT][WIDTH], char fileMap[HEIGHT][WIDTH]) = 0;
};

#endif
