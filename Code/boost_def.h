#ifndef BOOST_DEF_H
#define BOOST_DEF_H

#include "potion.h"

class BoostDef : public Potion{
  public:
    BoostDef(Position pos);
    void effect(Hero &hero) override;
};

#endif
