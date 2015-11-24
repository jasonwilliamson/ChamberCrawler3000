#include "potiondefense.h"

PotionDefense::PotionDefense(int val, int stat) : Potion(val, stat) {}

PotionDefense::~PotionDefense() {}

void PotionDefense::use(Player* player) {
    player->consume(this);
}
