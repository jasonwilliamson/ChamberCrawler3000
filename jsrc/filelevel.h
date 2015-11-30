//
//  filelevel.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef filelevel_hpp
#define filelevel_hpp

#include "level.h"
#include "floor.h"
#include "charboard.h"

class FileLevel: public Level{
private:
    CharBoard &cboard;
    Floor &floor;
    GameObject * initPlayer();
    GameObject * initPotion(char val, int potionType);
    GameObject * initTreasure(char val, int treasureType);
public:
    FileLevel(Floor &floor, CharBoard &cboard);
    ~FileLevel();
    void initLevel();
};


#endif /* filelevel_hpp */
