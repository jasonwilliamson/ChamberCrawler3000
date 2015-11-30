#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include "constants.h"

class Display {
    char grid[HEIGHT][WIDTH];
    std::string race, action;
    int gold, hp, atk, def;

  public:
    Display();
    ~Display();

    void draw(int state);
    void updateMap(int row, int col, char cell);
    void updateCharacter(std::string race, int gold, int hp, int atk, int def);
};

#endif
