//
//  vampire.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef vampire_hpp
#define vampire_hpp

#include "gameobject.h"
#include "player.h"

class Vampire : public Player {
  public:
    Vampire();
    ~Vampire();
    void use(Potion* p);
    void use(Treasure* g);
};

#endif
