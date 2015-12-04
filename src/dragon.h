//
//  dragon.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef dragon_hpp
#define dragon_hpp

#include "enemy.h"

class Dragon: public Enemy{
public:
    Dragon();
    ~Dragon();
    void update();
    void attack();
    int goldDropped();
};

#endif /* dragon_hpp */
