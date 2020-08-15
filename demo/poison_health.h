#ifndef POISON_HEALTH_H
#define POISON_HEALTH_H

#include "potion.h"
class PoisonHealth : public Potion{
  public:
    PoisonHealth(Position pos);
    void effect(Hero &hero) override;
};

#endif
