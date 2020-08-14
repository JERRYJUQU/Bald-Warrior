#ifndef WOUND_ATK_H
#define WOUND_ATK_H

#include "potion.h"
class WoundAtk : public Potion{
  public:
    WoundAtk(Position pos);
    void effect(Hero &hero) override;
};

#endif
