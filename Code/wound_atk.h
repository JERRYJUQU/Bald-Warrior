#ifndef WOUND_ATK_H
#define WOUND_ATK_H

#include "potion.h"
class WoundAtk :
    public Potion
{
    WoundAtk(int x, int y,
        std::shared_ptr <Observer> display);
    void effect(Hero &hero) override;
};

#endif