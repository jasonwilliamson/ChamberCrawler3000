//
//  normallevel.h
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef normallevel_hpp
#define normallevel_hpp

#include <vector>
#include "level.h"

class NormalLevel: public Level{
public:
    NormalLevel();
    ~NormalLevel();
    Cell *initLevel(Cell *cellGrind[HEIGHT][WIDTH], char blankMap[HEIGHT][WIDTH]);
private:
    
    std::vector<Cell *> chmbr1;
    std::vector<Cell *> chmbr2;
    std::vector<Cell *> chmbr3;
    std::vector<Cell *> chmbr4;
    std::vector<Cell *> chmbr5;
    std::vector < std::vector <Cell *> > chmbrArr;
    
    
    Cell * initLevelPlayer();
    void initStairway(std::vector<Cell *> chmbrOptions[4]);
    void initLevelPotions();
    void initLevelTreasure();
    void initLevelEnemy();
    Cell * getRandonChamberCell();
    std::vector<Cell *> getChamber(int chamberNumber);
    GameObject *initEnemy(char val);
};

#endif
