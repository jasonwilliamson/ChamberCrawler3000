#include "potion.h"

Potion::Potion() : GameObject("potion", 'P') {}

Potion::~Potion() {}

bool Potion::use() {
    return true;
}
