// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: player.h
// ====================================================
//

#ifndef player_hpp
#define player_hpp

#include "character.h"
#include "booster.h"

class Player :public Character{
private:
    //Booster activePotions;
public:
    Player();
    virtual ~Player();
};

#endif 
