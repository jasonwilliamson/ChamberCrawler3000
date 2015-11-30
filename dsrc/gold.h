#ifndef GOLD_H
#define GOLD_H
#include "gameobject.h"

class Gold : public GameObject {
  private:
    int value;

  public:
    Gold(int value);
    virtual ~Gold();

    bool use();

};

#endif
