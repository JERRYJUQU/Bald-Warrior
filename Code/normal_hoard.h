#ifndef NORMAL_HOARD_H
#define NORMAL_HOARD_H

#include "treasure.h"

class NormalHoard :
    public Treasure
{
    int amount = 2;
public:
    NormalHoard(int x, int y,
        std::shared_ptr <Observer> display);
    virtual void effect(Hero& hero) override;
};

#endif