//
//  troll.hpp
//

#ifndef troll_hpp
#define troll_hpp

#include "gameobject.h"
#include "player.h"

class Troll : public Player {
  public:
    Troll();
    ~Troll();
    void move(char dir);
    void use(Potion* p);
    void use(Treasure* g);
};

#endif
