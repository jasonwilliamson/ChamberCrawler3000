#include "potionhealth.h"

PotionHealth::PotionHealth(int val, int stat) : Potion(val, stat) {}

PotionHealth::~PotionHealth() {}

void PotionHealth::use(Game& game) {
    game.getPlayer().consume(*this);
}
