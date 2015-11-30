#include "gold.h"

Gold::Gold(int value) : GameObject("gold", 'G'), value(value) {}

Gold::~Gold() {}

bool Gold::use() {
    return true;

}
