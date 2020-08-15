#ifndef RESTORE_HEALTH_H
#define RESTORE_HEALTH_H

#include "potion.h"
class RestoreHealth : public Potion{
  public:
    RestoreHealth(Position pos);
    void effect(Hero &hero) override;
};

#endif
