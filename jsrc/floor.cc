#include <cstdlib>
#include "floor.h"
#include "cell.h"
#include "gameobject.h"

using namespace std;

Floor::Floor():grid(NULL) {
}

Floor::~Floor() {}

void Floor::setCellNormal(int row, int col, char defaultTile){
    grid[row][col] = Cell(row, col, defaultTile);
}

void Floor::setCellGameObject(int row, int col, char defaultTile, char gameObjectChar
                              , GameObject* gameObj){
    grid[row][col] = Cell(row, col, defaultTile, gameObjectChar, gameObj);
}

/*
void Floor::setCellwithDefaultSym(int row, int col, char defaultSym){
    grid[row][col] = Cell(row, col, defaultSym);
}

void Floor::setCellwithGameObjectSym(int row, int col, char defaultSym, char gameObjectSym) {
    grid[row][col] = Cell(row, col, defaultSym, gameObjectSym);
}

//sets cell game obj
void Floor::setCellGameObject(int row, int col, GameObject *gameObj){
    grid[row][col].setGameObject(gameObj);
}

char Floor::getCellDefualtChar(int row, int col) {
    return grid[row][col].getDefaultChar();
}

char Floor::getCellGameObjectChar(int row, int col){
    return grid[row][col].getGameObjectChar();
}

*/