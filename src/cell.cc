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
    row(row), column(column), defaultChar(' '), gameObjectChar(' '), gameObj(NULL),
    enemyBlockCount(0), playerBlockCount(0){}

Cell::~Cell(){
    delete gameObj;
}

void Cell::setGameObject(char gameObjectChar, GameObject *gameObj){
    this->defaultChar = '.'; //this needs to be modified
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
