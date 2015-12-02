//
//  drow.cpp
//

#include "drow.h"

#define HP 150
#define ATK 25
#define DEF 15

Drow::Drow():Player(HP,ATK,DEF, "Drow"){}

Drow::~Drow(){}

void Drow::move(char dir){
    
}

void Drow::use(Potion* p) {

}

void Drow::use(Treasure* g) {

}
