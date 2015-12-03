// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: player.cc
// ====================================================
//

#include <cstdlib>
#include <iostream>
#include "player.h"
#include "booster.h"

Player::Player(int hp, int atk, int def, std::string race)
    :Character(hp, atk, def), race(race) {
    this->activePotions = new Booster();
}

Player::~Player(){
    delete this->activePotions;
}

std::string Player::getRace() {
    return race;
}

void use(Treasure *t) {
    std::cout << "This is me using treasure" << std::endl;
}
