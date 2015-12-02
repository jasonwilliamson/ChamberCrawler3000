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
    int enemyBlockCount;
    int playerBlockCount;
    Cell *enemyBlockRadius[MAX_NEIGHBOURS];
    Cell *playerBlockRadius[MAX_NEIGHBOURS];
    GameObject *gameObj;
    
public:
    Cell(int row, int column);
    ~Cell();
    
    bool isPlayerWithinBlock();
    void addNeighbourBlock(Cell *block);
    char getCellChar();
    char getDefaultChar();
    void setDefaultChar(char);
    char getGameObjectChar();
    void setGameObject(char, GameObject *);
    GameObject* getGameObject();
    void randomizeEnemyMovement();
    void moveGameObject(char, GameObject *);
    
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
