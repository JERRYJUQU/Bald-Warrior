#ifndef WOUND_DEF_H
#define WOUND_DEF_H

#include "potion.h"
class WoundDef :
    public Potion
{
    WoundDef(int x, int y,
        std::shared_ptr <Observer> display);
    void effect(Hero &hero) override;
};

#endif