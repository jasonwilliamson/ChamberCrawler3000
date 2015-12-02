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

#include <string>
#include "character.h"
#include "booster.h"
#include "potion.h"
#include "treasure.h"

class Player : public Character {
  private:
//    const char displayChar;
    const std::string race;
  protected:
    Booster *activePotions;

  public:
    Player(int hp, int atk, int def, std::string race);
    ~Player();
    virtual void move(char dir) = 0;
    virtual void use(Potion* p) = 0;
    virtual void use(Treasure* g) = 0;
    std::string getRace();
//    char getDisplayChar();
};

#endif 
