#include "boost_atk.h"
#include "hero.h"

BoostAtk::BoostAtk(Position pos)
    : Potion(pos, PotionType::boostAtk)
{}

void BoostAtk::effect(Hero &hero) {
    int tempAtk = hero.getAtk() + 5;
    hero.setAtk(tempAtk);
}