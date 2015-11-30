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
    int row;
    int column;
    char defaultChar;
    char gameObjectChar;
    GameObject *gameObj;
    
public:
    Cell(int row, int column);
    ~Cell();
    
    char getCellChar();
    char getDefaultChar();
    void setDefaultChar(char);
    char getGameObjectChar();
    void setGameObject(char, GameObject *);
    int getGameObject();
    
    int getRow();
    int getColumn();
    void setRow(int);
    void setColumn(int);
    
    //void determineNeighbours()
    //notify neighboursOfPlayer
    //notify neighboursOfEnemy
    //notify neightboursOfDragonGold..or something
};

#endif
