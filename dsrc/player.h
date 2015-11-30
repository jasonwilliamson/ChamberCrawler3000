#ifndef PLAYER_H
#define PLAYER_H
#include "gameobject.h"

class Player : public GameObject {
  private:

  public:
    Player();
    virtual ~Player();

    virtual bool use();
};

#endif
