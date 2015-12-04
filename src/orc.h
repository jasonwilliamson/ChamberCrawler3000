//
//  orc.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef orc_hpp
#define orc_hpp

#include "enemy.h"

class Orc: public Enemy{
public:
    Orc();
    ~Orc();
    void update();
    void attack();
    int goldDropped();
};

#endif /* orc_hpp */
