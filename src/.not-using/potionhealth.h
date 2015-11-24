#ifndef POTIONHEALTH_H
#define POTIONHEALTH_H
#include "potion.h"

class PotionHealth : public Potion {
  public:
    PotionHealth(int val, int stat);
    ~PotionHealth();
    void use(Game& game);
};

#endif
