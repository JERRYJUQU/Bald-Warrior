#ifndef TREASRUE_H
#define TREASRUE_H

#include "item.h"
struct Position;

class Treasure :
    public Item
{
protected:
    bool canPickUp;
public:
    Treasure(Position pos, bool canPickUp = true);
    virtual void effect(Hero &hero) = 0;
    bool pickUp();
};

#endif
