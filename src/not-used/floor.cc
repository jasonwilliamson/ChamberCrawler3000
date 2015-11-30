#include "floor.h"

using namespace std;

Floor::Floor() {}

Floor::~Floor() {}

void Floor::setCell(int r, int c, char symbol) {
    grid[r][c] = symbol;
}

char Floor::getCell(int r, int c) {
    return grid[r][c];
}
