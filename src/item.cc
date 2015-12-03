#include "item.h"

Item::Item(int value, int type):value(value), type(type) {}

Item::~Item(){}

void Item::setValue(int v) {
    value = v;
}

int Item::getValue() {
    return value;
}

void Item::setType(int t) {
    type = t;
}

int Item::getType() {
    return type;
}
