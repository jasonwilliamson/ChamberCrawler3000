#ifndef ITEM_H
#define ITEM_H

class Game;

class Item {
    int value;
  public:
    Item(int val);
    virtual ~Item();
    virtual void use(Game& game);
    void setValue(int val);
    int getValue();
};

#endif
