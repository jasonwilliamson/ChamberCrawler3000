//
//  troll.cpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "troll.h"

#define HP 120
#define ATK 25
#define DEF 15

Troll::Troll():Player(HP,ATK,DEF, "Troll") {}

Troll::~Troll(){}

void Troll::move(char dir){
    
}

void Troll::use(Potion* p) {
    
}

void Troll::use(Treasure* g) {
    
}
