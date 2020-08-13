#ifndef NORMAL_HOARD_H
#define NORMAL_HOARD_H

#include "treasure.h"

class NormalHoard :
    public Treasure
{
    int amount = 2;
public:
    NormalHoard(Position pos);
    virtual void effect(Hero& hero) override;
};

#endif