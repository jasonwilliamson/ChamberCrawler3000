//
//  potion.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef potion_hpp
#define potion_hpp

#include "item.h"
#include "player.h"

class Potion : public Item {
  private:
    int potionType;
  public:
    Potion(char val, int potionType);
    ~Potion();
    void use(Player& player);
    void setType(int potionType);
    int getType();
};

#endif /* potion_hpp */
