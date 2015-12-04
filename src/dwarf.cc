//
//  dwarf.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "dwarf.h"
#include "character.h"

//100 HP, 20 Atk, 30 Def, Vampires are allergic to dwarves and lose 5HP rather than gain
#define HP 100
#define ATK 20
#define DEF 30
#define GOLD_DROPPED 2


Dwarf::Dwarf():Enemy(HP, ATK, DEF){}

Dwarf::~Dwarf(){}

void Dwarf::update(){}

void Dwarf::attack(){}

int Dwarf::goldDropped(){
    return GOLD_DROPPED;
}


