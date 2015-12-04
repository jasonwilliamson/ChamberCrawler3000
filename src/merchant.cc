//
//  merchant.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "merchant.h"
#include "character.h"

//merchant (30 HP, 70 Atk, 5 Def)

#define HP 30
#define ATK 70
#define DEF 5
#define GOLD_DROPPED 4

//140 HP, 20 Atk, 20 Def, drops 2 normal piles of gold

Merchant::Merchant():Enemy(HP, ATK, DEF){}

Merchant::~Merchant(){}

void Merchant::update(){}

void Merchant::attack(){}

int Merchant::goldDropped(){
    return GOLD_DROPPED;
}
