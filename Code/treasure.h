#ifndef TREASRUE_H
#define TREASRUE_H

#include "item.h"
class Treasure :
    public Item
{
public:
    Treasure(int x, int y,
        std::shared_ptr <Observer> display);
    virtual void effect(Hero &hero) = 0;
};

#endif