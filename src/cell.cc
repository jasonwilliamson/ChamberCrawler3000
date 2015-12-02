// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: cell.cc
// ====================================================
//

#include "cell.h"
#include <cstdlib>
#include <iostream>


using namespace std;

Cell::Cell(int row, int column):
    row(row), column(column), defaultChar(' '), gameObjectChar(' '), enemyBlockCount(0), playerBlockCount(0), gameObj(NULL) {}

Cell::~Cell(){
    delete gameObj;
}

void Cell::setGameObject(char gameObjectChar, GameObject *gameObj){
    this->defaultChar = '.'; //this needs to be modified
    this->gameObjectChar = gameObjectChar;
    this->gameObj = gameObj;
}

//update this cell with newly placed GameObject
void Cell::moveGameObject(char gameObjectChar, GameObject *gameObj){
    this->gameObjectChar = gameObjectChar;
    this->gameObj = gameObj;
}

void Cell::setDefaultChar(char c){
    this->defaultChar = c;
}

char Cell::getCellChar() {
    if(gameObj) {
        return gameObjectChar;
    } else {
        return defaultChar;
    }
}

char Cell::getDefaultChar(){
    return this->defaultChar;
}

GameObject* Cell::getGameObject(){
    return this->getGameObject();
}

//will move enemy randomly to // error here will move to any of the 8 blocks surround enemy
// need to only make up left right down possible moves.
void Cell::randomizeEnemyMovement(){
    int possible = 0;
    Cell *tmpArr[enemyBlockCount];
    for (int i = 0; i < enemyBlockCount; i++) {
        if (!enemyBlockRadius[i]->gameObj) {
            tmpArr[possible] = enemyBlockRadius[i];
            ++possible;
        }
    }
    int index = 0;
    if (possible != 0) {
        srand( static_cast<unsigned int>(time(NULL)));
        index = rand() % possible;
    }
    
    Cell *target = tmpArr[index];
    target->moveGameObject(this->gameObjectChar, this->gameObj);
    this->gameObj = NULL;
    this->gameObjectChar = ' ';
}


//determines if player is within 1 block radius of cell
bool Cell::isPlayerWithinBlock(){
    for (int i = 0; i < playerBlockCount; i++) {
        if (playerBlockRadius[i]->getCellChar() == '@') {
            return true;
        }
    }
    return false;
}

//only adds blocks where valid moves can be made
void Cell::addNeighbourBlock(Cell *block){
    char value = block->getDefaultChar();
    if (value == '.') {
        enemyBlockRadius[enemyBlockCount] = block;
        playerBlockRadius[playerBlockCount] = block;
        ++enemyBlockCount;
        ++playerBlockCount;
    }else if (value == '#' || value == '+' || value == '\\'){
        playerBlockRadius[playerBlockCount] = block;
        ++playerBlockCount;
    }
}
