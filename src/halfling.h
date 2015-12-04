//
//  halfling.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef halfling_hpp
#define halfling_hpp

#include "enemy.h"

class Halfling: public Enemy{
public:
    Halfling();
    ~Halfling();
    void update();
    void attack();
    int goldDropped();
};

#endif 
