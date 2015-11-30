//
//  vampire.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef vampire_hpp
#define vampire_hpp

#include "gameobject.h"
#include "player.h"

class Vampire: public Player{
private:
    
public:
    void move(char dir);
    void use(Item *);
    void setHp(int);
    int getHp();
    int getAtk();
    int getDef();
};



#endif
