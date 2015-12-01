//
//  filelevel.h
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef filelevel_hpp
#define filelevel_hpp

#include "level.h"
#include "constants.h"
#include "cell.h"
//#include "floor.h"
//#include "charboard.h"

class FileLevel: public Level{
private:
    //Cell *cellGrid[HEIGHT][WIDTH];
    //char *fileMap[HEIGHT][WIDTH];
    GameObject * initPlayer();
    GameObject * initPotion(char val, int potionType);
    GameObject * initTreasure(char val, int treasureType);
    GameObject * initEnemy(char val);
public:
    //FileLevel(Cell *cellGrid[HEIGHT][WIDTH], char *fileMap[HEIGHT][WIDTH]);
    FileLevel();
    ~FileLevel();
    void initLevel(Cell *cellGrid[HEIGHT][WIDTH], char fileMap[HEIGHT][WIDTH]);
};


#endif
