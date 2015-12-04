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

Cell::Cell(int row, int column):row(row), column(column), gameObj(NULL),enemyBlockCount(0),playerBlockCount(0),fullBlockCount(0) {}

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
    this->gameObj = NULL;
    this->gameObjectChar = ' ';
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
    if (this->gameObjectChar != 'D') {
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
        target->setGameObject(this->gameObjectChar, this->gameObj);
        this->gameObj = NULL;
        this->gameObjectChar = ' ';
    }
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

bool Cell::isDragonWithinBlock(){
    for (int i = 0; i < enemyBlockCount; i++) {
        if (enemyBlockRadius[i]->getCellChar() == 'D') {
            return true;
        }
    }
    return false;
}

Cell* Cell::getEmptyCellForDragon(){
    for (int i = 0; i <fullBlockCount; i++) {
        if (fullBlockRadius[i]) {
            return fullBlockRadius[i];
        }
    }
    cout << "error" << endl;
    return NULL;
}

void Cell::resetBlockRadii(){
    fullBlockCount = 0;
    playerBlockCount = 0;
    enemyBlockCount = 0;
}

//only adds blocks where valid moves can be made
void Cell::addNeighbourBlock(Cell *block){
    fullBlockRadius[fullBlockCount] = block;
    ++fullBlockCount;
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

