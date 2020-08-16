#ifndef POTION_H
#define POTION_H

#include "item.h"

enum class PotionType {restoreHealth, posionHealth, boostAtk, woundAtk, boostDef, woundDef, COUNT};

class Potion : public Item{
protected:
    PotionType type;
    bool used;
    double getScale(Hero &hero);
public:
    Potion(Position pos, PotionType type);
    virtual void effect(Hero &hero) = 0;
    PotionType getPotionType();
    void setUsed(bool b);
    bool getUsed();
};

#endif
