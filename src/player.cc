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

Player::Player(int hp, int atk, int def):Character(hp, atk, def){
    this->activePotions = new Booster();
}

Player::~Player(){
    delete this->activePotions;
}

