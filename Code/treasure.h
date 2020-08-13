#ifndef TREASRUE_H
#define TREASRUE_H

#include "item.h"

struct Position;

enum class TreasureType {small, normal, merchantHoard, dragonHoard};

class Treasure :
    public Item
{
protected:
    bool canPickUp;
    TreasureType type;
public:
    Treasure(Position pos, TreasureType type, bool canPickUp = true);
    virtual void effect(Hero &hero) = 0;
    bool pickUp();
    TreasureType getTreasureType();
};

#endif
