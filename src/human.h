//
//  human.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-11-30.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef human_hpp
#define human_hpp

#include "enemy.h"

class Human: public Enemy{
public:
    Human();
    ~Human();
    void update();
private:
};

#endif
