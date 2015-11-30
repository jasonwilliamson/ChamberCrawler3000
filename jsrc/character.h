// ====================================================
// Jason Williamson (20552360)
// David Inglis
// CS 246 Fall 2015
// Assignment 05, CC3K
// File: character.h
// ====================================================
//

#ifndef character_hpp
#define character_hpp

#include "gameobject.h"

class Character: public GameObject{
protected:
    int hp;
    int atk;
    int def;
    
public:
//    Character();
    Character(int hp, int atk, int def);
    virtual ~Character();
    void setHP(int);
    int getHp();
    int getAtk();
    int getDef();
};

#endif /* character_hpp */
