//
//  elf.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef elf_hpp
#define elf_hpp

#include "enemy.h"

class Elf: public Enemy{
public:
    Elf();
    ~Elf();
    void update();
    void attack();
    int goldDropped();
};

#endif /* elf_hpp */
