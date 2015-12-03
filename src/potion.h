#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "constants.h"

class Potion : public Item {
  private:

  public:
    Potion(int value, int type);
    ~Potion();
};

#endif
