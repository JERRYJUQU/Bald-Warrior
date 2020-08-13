#ifndef BOOST_ATK_H
#define BOOST_ATK_H

#include "potion.h"

class BoostAtk :
    public Potion
{
    BoostAtk(Position pos);
    void effect(Hero &hero) override;
};

#endif