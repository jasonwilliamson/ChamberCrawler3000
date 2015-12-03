#ifndef ITEM_H
#define ITEM_H

#include "gameobject.h"

class Item : public GameObject {
  private:
    int value;
    int type;

  public:
    Item(int value, int type);
    virtual ~Item();
    void setValue(int);
    int getValue();
    void setType(int);
    int getType();
};

#endif
