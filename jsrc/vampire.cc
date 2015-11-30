//
//  vampire.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "vampire.h"
#include <cstdlib>

//TODO modify
#define HP 125
#define ATK 25
#define DEF 25

Vampire::Vampire():Player(HP,ATK,DEF){}

Vampire::~Vampire(){}

void Vampire::move(char dir){
    
}

void Vampire::use(Item *itm){
    
}

void Vampire::setHp(int hp){
    this->hp = hp;
}

int Vampire::getHp(){
    return this->hp;
}

int Vampire::getAtk(){
    return this->atk;
}

int Vampire::getDef(){
    return this->def;
}