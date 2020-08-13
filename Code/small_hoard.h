#ifndef SMALL_HOARD_H
#define SMALL_HOARD_H

#include "treasure.h"

class SmallHoard :
    public Treasure
{
    int amount = 1;
public:
    SmallHoard(Position pos);
    virtual void effect(Hero& hero) override;
};

#endif