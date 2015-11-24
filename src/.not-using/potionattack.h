#ifndef POTIONATTACK_H
#define POTIONATTACK_H
#include "potion.h"

class PotionAttack : public Potion {
  public:
    PotionAttack(int val, int stat);
    ~PotionAttack();
    void use(Game& game);
};

#endif
