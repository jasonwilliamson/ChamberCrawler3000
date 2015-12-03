#ifndef treasure_hpp
#define treasure_hpp

#include "item.h"

class Treasure : public Item {
  private:

  public:
    Treasure(int val, int type);
    ~Treasure();
    bool isDragonHoard();
};

#endif
