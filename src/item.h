//
//  item.hpp
//  loadingFromFile
//
//  Created by Jason Williamson on 2015-11-29.
//  Copyright © 2015 Jason Williamson. All rights reserved.
//

#ifndef item_hpp
#define item_hpp

#include "gameobject.h"

class Item: public GameObject{
public:
    Item(int value);
    virtual ~Item();
};

#endif /* item_hpp */
