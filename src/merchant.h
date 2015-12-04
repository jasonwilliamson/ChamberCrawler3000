//
//  merchant.hpp
//  cc3k
//
//  Created by Jason Williamson on 2015-12-03.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef merchant_hpp
#define merchant_hpp

#include "enemy.h"

class Merchant: public Enemy{
public:
    Merchant();
    ~Merchant();
    void update();
    void attack();
    int goldDropped();
};

#endif 
