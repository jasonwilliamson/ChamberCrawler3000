#ifndef ENEMY_H
#define ENEMY_H
#include "gameobject.h"
#include "character.h"

class Enemy : public Character {
  public:
    Enemy(int hp, int atk, int def);
    ~Enemy();
    virtual void update() = 0;
    virtual void attack() = 0;
    virtual int goldDropped() = 0;
};

#endif
