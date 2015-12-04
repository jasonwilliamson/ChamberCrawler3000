//
//  enemycatalogue.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-01.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "enemycatalogue.h"
#include <iostream>
#include "enemy.h"
#include "human.h"
#include "character.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"

using namespace std;

EnemyCatalogue::EnemyCatalogue(){}

EnemyCatalogue::~EnemyCatalogue(){}

bool EnemyCatalogue::isEnemy(char value){
    if ('H' == value || 'W' == value || 'E' == value || 'O' == value ||
        'M' == value || 'D' == value || 'L' == value) {
        return true;
    }else{
        return false;
    }
}

int EnemyCatalogue::getAtk(char value){
    switch (value) {
        case 'H':
        {
            Human enemy = Human();
            return enemy.getAtk();
            break;
        }
        case 'W':
        {
            Dwarf enemy = Dwarf();
            return enemy.getAtk();
        }
        case 'E':
        {
            Elf enemy = Elf();
            return enemy.getAtk();
        }
        case 'O':
        {
            Orc enemy = Orc();
            return enemy.getAtk();
        }
        case 'M':
        {
            Merchant enemy = Merchant();
            return enemy.getAtk();
        }
        case 'L':
        {
            Halfling enemy = Halfling();
            return enemy.getAtk();
        }
        case 'D':
        {
            Dragon enemy = Dragon();
            return enemy.getAtk();
        }
        default:
        {
            cout << "Error EnemyCatalogue:@getAtk " << value << " not recognized" << endl;
            break;
        }
    }
    return 0;
}

int EnemyCatalogue::getGoldDropped(char value){
    switch (value) {
        case 'H':
        {
            Human enemy = Human();
            return enemy.goldDropped();
            break;
        }
        case 'W':
        {
            Dwarf enemy = Dwarf();
            return enemy.goldDropped();
        }
        case 'E':
        {
            Elf enemy = Elf();
            return enemy.goldDropped();
        }
        case 'O':
        {
            Orc enemy = Orc();
            return enemy.goldDropped();
        }
        case 'M':
        {
            Merchant enemy = Merchant();
            return enemy.goldDropped();
        }
        case 'L':
        {
            Halfling enemy = Halfling();
            return enemy.goldDropped();
        }
        case 'D':
        {
            Dragon enemy = Dragon();
            return enemy.goldDropped();
        }
        default:
        {
            cout << "Error EnemyCatalogue:@getGoldDropped " << value << " not recognized" << endl;
            break;
        }
    }
    return 0;
}


