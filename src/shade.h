//
//  shade.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef shade_hpp
#define shade_hpp

#include "gameobject.h"
#include "player.h"

class Shade: public Player{
private:
    
public:
    Shade();
    ~Shade();
    void move(char dir);
    void use(Item *);
    //void setHp(int);
    int getHp();
    int getAtk();
    int getDef();
};

#endif
