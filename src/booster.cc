// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: booster.cc
// ====================================================
//

#include "booster.h"

Booster::Booster():atk(0), def(0) {}

Booster::Booster(int atk, int def):atk(atk), def(def) {}

Booster::~Booster() {}

void Booster::reset() {
    atk = 0; def = 0;
}

void Booster::addAtk(int a) {
    atk += a;
}

void Booster::addDef(int d) {
    def += d;
}

void Booster::removeAtk(int a) {
    atk -= a;
}

void Booster::removeDef(int d) {
    def -= d;
}

int Booster::getAtk() {
    return atk;
}

int Booster::getDef() {
    return def;
}
