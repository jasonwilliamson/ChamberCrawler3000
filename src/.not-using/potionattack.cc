#include "potionattack.h"

PotionAttack::PotionAttack(int val, int stat) : Potion(val, stat) {}

PotionAttack::~PotionAttack() {}

void PotionAttack::use(Game& game) {
    game.getPlayer().consume(*this);
}
