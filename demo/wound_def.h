#ifndef WOUND_DEF_H
#define WOUND_DEF_H

#include "potion.h"
class WoundDef :public Potion{
  public:
    WoundDef(Position pos);
    void effect(Hero &hero) override;
};

#endif
