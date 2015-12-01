// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: character.cc
// ====================================================
//

#include "character.h"

Character::Character(int hp, int atk, int def):hp(hp), atk(atk), def(def){}

Character::~Character(){}

int Character::getAtk(){
    return this->atk;
}

int Character::getHp(){
    return this->hp;
}

int Character::getDef(){
    return this->def;
}

int Character::getGold() { 
    return this->gold;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

void Character::setAtk(int atk) {
    this->atk = atk;
}

void Character::setDef(int def) {
    this->def = def;
}

void Character::setGold(int gold) {
    this->gold = gold;
}
