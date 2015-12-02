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

Cell::Cell(int row, int column):row(row), column(column), gameObj(NULL) {}

Cell::~Cell(){
    delete gameObj;
}

char Cell::getCellChar() {
    if (gameObj) {
        return gameObjectChar;
    } else {
        return defaultChar;
    }
}

char Cell::getDefaultChar(){
    return defaultChar;
}

void Cell::setDefaultChar(char c){
    defaultChar = c;
}

char Cell::getGameObjectChar() {
    return gameObjectChar;
}

void Cell::setGameObjectChar(char c) {
    gameObjectChar = c;
}

GameObject* Cell::getGameObject(){
    return gameObj;
}

void Cell::setGameObject(char gameObjectChar, GameObject *gameObj){
    this->gameObjectChar = gameObjectChar;
    this->gameObj = gameObj;
}

void Cell::removeGameObject() {
    gameObj = NULL;
}

int Cell::getRow() {
    return row;
}

int Cell::getColumn() {
    return column;
}

void Cell::setRow(int r) {
    row = r;
}

void Cell::setColumn(int c) {
    column = c;
}

//will move enemy randomly within the one block radius of current cell
void Cell::randomizeEnemyMovement(){
    int possible = 0;
    cout << "randomizeEnemyMovement: enemyBlockCount " << enemyBlockCount << endl;
    Cell *tmpArr[enemyBlockCount];
    for (int i = 0; i < enemyBlockCount; i++) {
        if (!enemyBlockRadius[i]->gameObj) {
            tmpArr[possible] = enemyBlockRadius[i];
            ++possible;
        }
    }
    cout << "possible count : " << possible << endl;
    int index = 0;
    if (possible != 0) {
        srand( static_cast<unsigned int>(time(NULL)));
        index = rand() % possible;
    }

    Cell *target = tmpArr[index];
    target->setGameObject(this->gameObjectChar, this->gameObj);
    cout << "moving enemy row: " << this->row <<" col: " << this->column << "To row: " << target->row << " col: " << target->column << endl;
    this->gameObj = NULL;
    this->gameObjectChar = ' ';
}


//determines if player is within 1 block radius of cell
bool Cell::isPlayerWithinBlock(){
    cout << "Cell:isPlayerWithinBlock playerBlockCount: " << playerBlockCount << endl;
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

