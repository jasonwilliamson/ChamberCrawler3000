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
#include "item.h"

class Player :public Character{
protected:
    Booster *activePotions;
public:
    Player(int hp, int atk, int def);
    virtual ~Player();
    virtual void move(char dir);
    virtual void use(Item *);
    virtual void setHp(int);
    virtual int getHp();
    virtual int getAtk();
    virtual int getDef();
};

#endif 