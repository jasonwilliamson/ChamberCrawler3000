#include "item.h"

Item::Item(int val) : value(val) {}

Item::~Item() {}

void Item::setValue(int val) {
    value = val;
}

int Item::getValue() {
    return value;
}
