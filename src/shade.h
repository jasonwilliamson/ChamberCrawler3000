//
//  shade.hpp
//

#ifndef shade_hpp
#define shade_hpp

#include "gameobject.h"
#include "player.h"

class Shade : public Player{
  public:
    Shade();
    ~Shade();
    void move(char dir);
    void use(Potion* p);
    void use(Treasure* g); 
};

#endif
