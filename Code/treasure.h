#ifndef TREASRUE_H
#define TREASRUE_H

#include "item.h"
class Treasure :
    public Item
{
protected:
    bool canPickUp;
public:
    Treasure(int x, int y,
        std::shared_ptr <Observer> display, bool canPickUp = true);
    virtual void effect(Hero &hero) = 0;
    bool pickUp();
};

#endif