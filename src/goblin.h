//
//  goblin.hpp
//

#ifndef goblin_hpp
#define goblin_hpp

#include "gameobject.h"
#include "player.h"

class Goblin : public Player {
  public:
    Goblin();
    ~Goblin();
    void move(char dir);
    void use(Potion* p);
    void use(Treasure* g);
};

#endif
