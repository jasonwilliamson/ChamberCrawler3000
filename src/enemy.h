#ifndef ENEMY_H
#define ENEMY_H
#include "gameobject.h"

class Enemy : public GameObject {
  private:
  public:
    Enemy();
    ~Enemy();

    virtual bool use();
};

#endif
