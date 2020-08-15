#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H

#include "treasure.h"

class DragonHoard :
    public Treasure
{
    int amount = 6;
public:
    DragonHoard(Position pos);
    virtual void effect(Hero& hero) override;
    void notifyDeath();
};

#endif