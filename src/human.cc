//
//  human.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-11-30.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "human.h"
#include "character.h"

//drops 2 normal piles of gold

#define HP 140
#define ATK 20
#define DEF 20
#define GOLD_DROPPED 4

//140 HP, 20 Atk, 20 Def, drops 2 normal piles of gold

Human::Human():Enemy(HP, ATK, DEF){}

Human::~Human(){}

void Human::update(){}

void Human::attack(){}

int Human::goldDropped(){
    return GOLD_DROPPED;
}