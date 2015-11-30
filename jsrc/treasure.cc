//
//  treasure.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "treasure.h"
#include "item.h"

Treasure::Treasure(char val, int treasureType):Item(val), treasureType(treasureType){}

Treasure::~Treasure(){}

int Treasure::getValue(){
    return this->treasureType;
}

bool Treasure::isDragonHoard(){
    //TO DO check type
    return false;
}