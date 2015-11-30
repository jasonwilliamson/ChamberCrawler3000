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
    int row;
    int column;
    char defaultChar;
    char gameObjectChar;
    
public:
    //Cell();
    //Cell(int row, int column, char defualtChar);
    //Cell(int row, int column, char defaultChar, char gameObjectChar);
    Cell(int row, int column, char defaultChar);
    Cell(int row, int column, char defaultChar, char gameObjectChar, GameObject* gameObj);
    ~Cell();
    char getDefaultChar();
    void setDefaultChar(char);
    char getGameObjectChar();
    void setGameObjectChar(char);
    void setGameObject(GameObject *);
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

#endif /* cell_hpp */
