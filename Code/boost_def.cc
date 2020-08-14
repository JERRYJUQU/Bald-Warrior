#include "boost_def.h"
#include "hero.h"

BoostDef::BoostDef(Position pos)
    : Potion(pos, PotionType::boostDef)
{}

void BoostDef::effect(Hero &hero) {
    int tempDef = hero.getDef() + 5;
    hero.setAtk(tempDef);
}