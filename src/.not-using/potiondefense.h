#ifndef POTIONDEFENSE_H
#define POTIONDEFENSE_H
#include "potion.h" 

class PotionDefense : public Potion {
  public:
    PotionDefense(int val, int stat);
    ~PotionDefense();
    void use(Game& game);
};

#endif
