//
//  dragon.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "dragon.h"
#include "character.h"

//dragon (150 HP, 20 Atk, 20 Def, always guards a treasure hoard),

#define HP 150
#define ATK 20
#define DEF 20
#define GOLD_DROPPED 6

Dragon::Dragon():Enemy(HP, ATK, DEF){}

Dragon::~Dragon(){}

void Dragon::update(){}

void Dragon::attack(){}

int Dragon::goldDropped(){
    return GOLD_DROPPED;
}