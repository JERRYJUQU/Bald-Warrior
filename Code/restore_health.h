#ifndef RESTORE_HEALTH_H
#define RESTORE_HEALTH_H

#include "potion.h"
class RestoreHealth :
    public Potion
{
    RestoreHealth(int x, int y,
        std::shared_ptr <Observer> display);
    void effect(Hero &hero) override;
};

#endif