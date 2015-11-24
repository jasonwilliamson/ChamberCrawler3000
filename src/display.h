#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include "constants.h"

class Display {
    char grid[HEIGHT][WIDTH];

  public:
    Display();
    ~Display();

    void draw();
    void setCell(int r, int c, char symbol);
};

#endif
