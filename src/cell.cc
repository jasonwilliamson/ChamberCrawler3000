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

Cell::Cell(int row, int column):row(row), column(column), defaultChar(' '), gameObjectChar(' '), gameObj(NULL){}

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
