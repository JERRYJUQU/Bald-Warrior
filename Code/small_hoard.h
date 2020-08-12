#ifndef SMALL_HOARD_H
#define SMALL_HOARD_H

#include "treasure.h"

class SmallHoard :
    public Treasure
{
    int amount = 1;
public:
    SmallHoard(int x, int y, 
        std::shared_ptr <Observer> display);
    virtual void effect(Hero& hero) override;
};

#endif