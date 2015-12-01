//
//  potion.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "potion.h"
#include "item.h"

#define RH = 0
#define BA = 1
#define BD = 2
#define PH = 3
#define WA = 4
#define WD = 5

Potion::Potion(char val, int potionType):Item(val), potionType(potionType){}

Potion::~Potion(){}

//void Potion::use(Player& player){}

void Potion::setType(int potionType){
    this->potionType = potionType;
}

int Potion::getType(){
    return this->potionType;
}

