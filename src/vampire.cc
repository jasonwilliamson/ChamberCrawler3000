//
//  vampire.cpp
//

#include "vampire.h"

#define HP 50
#define ATK 25
#define DEF 25

Vampire::Vampire():Player(HP,ATK,DEF, "Vampire"){}

Vampire::~Vampire(){}

void Vampire::use(Potion* p) {

}

void Vampire::use(Treasure *) { 
    
}
