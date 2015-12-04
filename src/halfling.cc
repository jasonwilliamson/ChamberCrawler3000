//
//  halfling.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "halfling.h"
#include "character.h"

#define HP 100
#define ATK 15
#define DEF 20
#define GOLD_DROPPED 2

//(100 HP, 15 Atk, 20 Def, has a 50% chance to cause the player character to miss in
// combat, i.e., takes priority over player character’s ability to never miss).

Halfling::Halfling():Enemy(HP, ATK, DEF){}

Halfling::~Halfling(){}

void Halfling::update(){}

void Halfling::attack(){}

int Halfling::goldDropped(){
    return GOLD_DROPPED;
}