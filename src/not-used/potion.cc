#include "potion.h"

Potion::Potion(int val, potion_t type) : Item(val), type(type) {}

Potion::~Potion() {}

void Potion::use(Game& game) {
    game.getPlayer().consume(*this);
}

void Potion::setType(potion_t type) {
    this->type = type;
}

potion_t Potion::getType() {
    return type;
}
