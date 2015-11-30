#ifndef LEVEL_H
#define LEVEL_H
#include <cstdlib>
#include "gameobject.h"
#include "cell.h"
#include "constants.h"
#include "player.h"
#include "enemy.h"
#include "potion.h"
#include "gold.h"

class Level {
  public:
    Level();
    ~Level();

    void generate(Cell* cells[HEIGHT][WIDTH]);
    void generate(Cell* cells[HEIGHT][WIDTH], char data[HEIGHT][WIDTH]);
};

#endif
