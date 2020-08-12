#ifndef BOOST_DEF_H
#define BOOST_DEF_H

#include "potion.h"
class BoostDef :
    public Potion
{
    BoostDef(int x, int y,
        std::shared_ptr <Observer> display);
    void effect(Hero &hero) override;
};

#endif