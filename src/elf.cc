//
//  elf.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "elf.h"
#include "enemy.h"
#include "character.h"

#define HP 140
#define ATK 30
#define DEF 10
#define GOLD_DROPPED 2

//(140 HP, 30 Atk, 10 Def, gets two attacks against every race except drow)

Elf::Elf():Enemy(HP, ATK, DEF){}

Elf::~Elf(){}

void Elf::update(){}

void Elf::attack(){}

int Elf::goldDropped(){
    return GOLD_DROPPED;
}