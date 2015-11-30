#ifndef POTION_H
#define POTION_H
#include "gameobject.h"

class Potion : public GameObject {
  private:
    //potion types;

  public:
    Potion();
    virtual ~Potion();

    bool use();
};

#endif
