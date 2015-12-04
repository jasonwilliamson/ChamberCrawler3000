//
//  orc.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "orc.h"
#include "enemy.h"
#include "character.h"

#define HP 180
#define ATK 30
#define DEF 25
#define GOLD_DROPPED 2

//180 HP, 30 Atk, 25 Def, does 50% more damage to goblins

Orc::Orc():Enemy(HP, ATK, DEF){}

Orc::~Orc(){}

void Orc::update(){}

void Orc::attack(){}

int Orc::goldDropped(){
    return GOLD_DROPPED;
}