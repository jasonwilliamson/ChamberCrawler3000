//
//  human.cpp
//  cc3k
//
//  Created by Jason Williamson on 2015-11-30.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#include "human.h"
#include "character.h"

#define HP 125
#define ATK 25
#define DEF 25

Human::Human():Enemy(HP, ATK, DEF){}

Human::~Human(){}

void Human::update(){}