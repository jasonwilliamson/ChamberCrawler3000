//
//  treasure.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef treasure_hpp
#define treasure_hpp

#include "item.h"

class Treasure: public Item{
public:
    Treasure(int val, int type);
    ~Treasure();
    bool isDragonHoard();
private:
    int treasureType;
};

#endif /* treasure_hpp */
