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

Cell::Cell(int row, int column, char defaultChar):
    row(row), column(column), defaultChar(defaultChar), gameObjectChar(' '), gameObj(NULL){}

Cell::Cell(int row, int column, char defaultChar, char gameObjectChar, GameObject* gameObj):
    row(row), column(column),defaultChar(defaultChar), gameObjectChar(gameObjectChar), gameObj(gameObj){}

Cell::~Cell(){
    delete gameObj;
}

bool Cell::isStairs(){
    if (this->defaultChar == '\\') {
        return true;
    }
    return false;
}

char Cell::getDefaultChar(){
    return this->defaultChar;
}

void Cell::setDefaultChar(char value){
    this->defaultChar = value;
}

char Cell::getGameObjectChar(){
    return this->gameObjectChar;
}

void Cell::setGameObjectChar(char value){
    this->gameObjectChar = value;
}

void Cell::setGameObject(GameObject *obj){
    this->gameObj = obj;
}

GameObject* Cell::getGameObject(){
    return this->gameObj;
}

int Cell::getRow(){
    return this->row;
}

int Cell::getColumn(){
    return this->column;
}

void Cell::setRow(int row){
    this->row = row;
}

void Cell::setColumn(int col){
    this->column = col;
}



