#include "boost_def.h"
#include "hero.h"

BoostDef::BoostDef(int x, int y,
    std::shared_ptr <Observer> display)
    : Potion(x, y, display)
{}

void BoostDef::effect(Hero &hero) {
    int tempDef = hero.getDef() + 5;
    hero.setAtk(tempDef);
}