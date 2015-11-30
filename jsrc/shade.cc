//
//  shade.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "shade.h"

#define HP 125
#define ATK 25
#define DEF 25

Shade::Shade():Player(HP,ATK,DEF){}

Shade::~Shade(){}

void Shade::move(char dir){
    
}

void Shade::use(Item *itm){
    
}

int Shade::getHp(){
    return this->hp;
}

int Shade::getAtk(){
    return this->atk;
}

int Shade::getDef(){
    return this->def;
}
