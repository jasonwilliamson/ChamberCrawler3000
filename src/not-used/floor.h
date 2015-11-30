#ifndef FLOOR_H
#define FLOOR_H
#include "constants.h"

class Floor {
    char grid[HEIGHT][WIDTH];

  public:
    Floor();
    ~Floor();
    
    void setCell(int r, int c, char symbol);
    char getCell(int r, int c);
};

#endif
