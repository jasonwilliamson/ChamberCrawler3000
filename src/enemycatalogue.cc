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
        default:
        {
            cout << "Error EnemyCatalogue:@getGoldDropped " << value << " not recognized" << endl;
            break;
        }
    }
    return 0;
}


//void EnemyCatalogue::lookup(Human &h){
//    cout << "Human found: EnemyCatalogue" << endl;
//}