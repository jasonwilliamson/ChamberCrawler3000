//
//  enemycatalogue.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-01.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef enemycatalogue_hpp
#define enemycatalogue_hpp

#include <cstdlib>
#include <iostream>
#include "human.h"
#include "enemy.h"
#include "character.h"

class EnemyCatalogue {
    
public:
    EnemyCatalogue();
    ~EnemyCatalogue();
    int getAtk(char);
    bool isEnemy(char);
    int getGoldDropped(char value);
    std::string getRace(char value);
};

#endif 
