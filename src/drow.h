//
//  drow.hpp
//

#ifndef drow_hpp
#define drow_hpp

#include "gameobject.h"
#include "player.h"

class Drow: public Player{
private:
    
public:
    void move(char dir);
    void use(Potion* p);
    void use(Treasure* g);
};

#endif
