#ifndef POISON_HEALTH_H
#define POISON_HEALTH_H

#include "potion.h"
class PoisonHealth :
    public Potion
{
    PoisonHealth(int x, int y,
        std::shared_ptr <Observer> display);
    void effect(Hero &hero) override;
};

#endif