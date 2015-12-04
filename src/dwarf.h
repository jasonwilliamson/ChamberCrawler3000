//
//  dwarf.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef dwarf_hpp
#define dwarf_hpp

#include "enemy.h"

class Dwarf: public Enemy{
public:
    Dwarf();
    ~Dwarf();
    void update();
    void attack();
    int goldDropped();
};


#endif 
