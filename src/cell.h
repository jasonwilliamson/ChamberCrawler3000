#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "gameobject.h"


class Cell {
  private:
    int row;
    int col;
    GameObject* gameObject;

  public:
    Cell(int row, int col);
    Cell(int row, int col, GameObject* go);
    ~Cell();

    void setGameObject(GameObject* go);
    void setCoordinates(int row, int col);
    int getRow();
    int getColumn();
    GameObject* getGameObject();
    char getDisplayChar();
};

#endif
