//
//  treasure.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "treasure.h"
#include "item.h"

Treasure::Treasure(int val, int type):Item(val), treasureType(type) {}

Treasure::~Treasure(){}

bool Treasure::isDragonHoard(){
    if (treasureType == 2) {
        return true;
    } else {
        return false;
    }
}
