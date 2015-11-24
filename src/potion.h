#ifndef POTION_H
#define POTION_H
#include "item.h"

enum potion_t = {RestoreHealth, BoostAttack, BoostDefense, PoisonHealth, WoundAttack, WoundDefense};

class Game;

class Potion : public Item {
    potion_t type;
  public:
    Potion(int val, potion_t type);
    ~Potion();
    use(Game& game);
    void setType(potion_t type);
    potion_t getType();
};

#endif
