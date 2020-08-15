#include "wound_atk.h"
#include "hero.h"

WoundAtk::WoundAtk(Position pos)
    : Potion(pos, PotionType::woundAtk)
{}

void WoundAtk::effect(Hero &hero) {
    int tempAtk = hero.getAtk() - (int) (getScale(hero)*5);
    if (tempAtk < 1) {
        hero.setAtk(0);
        return;
    }
    hero.setAtk(tempAtk);
}
