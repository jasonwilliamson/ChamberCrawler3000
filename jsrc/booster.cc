// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: booster.cc
// ====================================================
//

#include "booster.h"

Booster::Booster():attack(0), defence(0){}

Booster::Booster(int atk, int def):attack(atk), defence(def){}

Booster::~Booster(){}

void Booster::reset(){}

void Booster::setAttack(int atk){
    this->attack = atk;
}

void Booster::setDefence(int def){
    this->defence = def;
}

int Booster::getAttack(){
    return this->attack;
}

int Booster::getDefence(){
    return this->defence;
}




