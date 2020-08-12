#include "boost_atk.h"
#include "hero.h"

BoostAtk::BoostAtk(int x, int y,
    std::shared_ptr <Observer> display)
    : Potion(x, y, display)
{}

void BoostAtk::effect(Hero &hero) {
    int tempAtk = hero.getAtk() + 5;
    hero.setAtk(tempAtk);
}