#include "treasure.h"
#include "item.h"

Treasure::Treasure(int value, int type):Item(value, type) {}

Treasure::~Treasure(){}

bool Treasure::isDragonHoard(){
    if (getType() == 2) {
        return true;
    } else {
        return false;
    }
}
