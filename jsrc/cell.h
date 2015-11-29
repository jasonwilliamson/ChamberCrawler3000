// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: cell.h
// ====================================================
//

#ifndef cell_hpp
#define cell_hpp

#include "gameobject.h"

class Cell{
private:
    GameObject *gameObj;
    
public:
    Cell();
    ~Cell();
};

#endif /* cell_hpp */
