#ifndef BOOST_ATK_H
#define BOOST_ATK_H

#include "potion.h"
class BoostAtk :
    public Potion
{
    BoostAtk(int x, int y,
        std::shared_ptr <Observer> display);
    void effect(Hero &hero) override;
};

#endif