//
//  shade.cpp
//

#include "shade.h"

#define HP 125
#define ATK 25
#define DEF 25

Shade::Shade():Player(HP,ATK,DEF, "Shade") {}

Shade::~Shade(){}

void Shade::use(Potion* p) {
    
}

void Shade::use(Treasure* g) {

}
