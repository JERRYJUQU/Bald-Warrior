#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion : public Item{
public:
    Potion(Position pos);
    //virtual void effect(Hero &hero) = 0;
};

#endif
