//
//  troll.cpp
//

#include "troll.h"

#define HP 120
#define ATK 25
#define DEF 15

Troll::Troll():Player(HP,ATK,DEF, "Troll") {}

Troll::~Troll(){}

void Troll::use(Potion* p) {
    
}

void Troll::use(Treasure* g) {
    
}
