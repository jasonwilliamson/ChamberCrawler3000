#ifndef filelevel_hpp
#define filelevel_hpp

#include "level.h"
#include "constants.h"

class FileLevel : public Level {
  private:
    GameObject* initPlayer();
    GameObject* initPotion(int value, int type);
    GameObject* initTreasure(int value, int type);
    GameObject* initEnemy(char race);

  public:
    Cell* initLevel(Cell *cellGrid[HEIGHT][WIDTH], char fileMap[HEIGHT][WIDTH]);
};


#endif
