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

const int MAX_NEIGHBOURS = 8;

class Cell{
private:
    int row;
    int column;
    char defaultChar;
    char gameObjectChar;
    Cell *enemyBlockRadius[MAX_NEIGHBOURS];
    Cell *playerBlockRadius[MAX_NEIGHBOURS];
    Cell *fullBlockRadius[MAX_NEIGHBOURS];
    GameObject *gameObj;
    int enemyBlockCount;
    int playerBlockCount;
    int fullBlockCount;
    
public:
    Cell(int row, int column);
    ~Cell();
    
    char getCellChar();
    char getDefaultChar();
    void setDefaultChar(char);
    char getGameObjectChar();
    void setGameObjectChar(char);
    GameObject* getGameObject();
    void setGameObject(char, GameObject *);
    void removeGameObject();
    int getRow();
    void setRow(int);
    int getColumn();
    void setColumn(int);
    void setChamberNumber(int);
    int getChamberNumber();
    void resetBlockRadii();

    bool isPlayerWithinBlock();
    void addNeighbourBlock(Cell *block);
    void randomizeEnemyMovement();
    bool isDragonWithinBlock();
    Cell *getEmptyCellForDragon();
    
    
    //void determineNeighbours()
    //notify neighboursOfPlayer
    //notify neighboursOfEnemy
    //notify neightboursOfDragonGold..or something
};

#endif
