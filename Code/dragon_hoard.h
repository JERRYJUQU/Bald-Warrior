#ifndef DRAGON_HOARD_H
#define DRAGON_HOARD_H

#include "treasure.h"

class DragonHoard :
    public Treasure
{
    int amount = 6;
public:
    DragonHoard(int x, int y,
        std::shared_ptr <Observer> display);
    virtual void effect(Hero& hero) override;
    void notifyDeath();
};

#endif