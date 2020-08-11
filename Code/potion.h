#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion :
    public Item
{
public:
    Potion(int x, int y, 
        std::shared_ptr <Observer> display);
    virtual void effect(Hero &hero) = 0;
};

#endif