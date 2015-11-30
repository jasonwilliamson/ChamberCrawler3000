#include "cell.h"

Cell::Cell(int row, int col)
    :row(row), col(col), gameObject(NULL) {}

Cell::Cell(int row, int col, GameObject *go)
    :row(row), col(col), gameObject(go) {}

Cell::~Cell() {
    delete gameObject;
}

void Cell::setGameObject(GameObject* go) {
    gameObject = go;
}

void Cell::setCoordinates(int row, int col) {
    this->row = row;
    this->col = col;
}

int Cell::getRow() { return row; }

int Cell::getColumn() { return col; }

GameObject* Cell::getGameObject() { return gameObject; }

char Cell::getDisplayChar() {
    if (gameObject) {
        return gameObject->getDisplayChar();
    } else {
        return 'n';
    }
}
