#include "wound_atk.h"
#include "hero.h"

WoundAtk::WoundAtk(int x, int y,
    std::shared_ptr <Observer> display)
    : Potion(x, y, display)
{}

void WoundAtk::effect(Hero &hero) {
    int tempAtk = hero.getAtk() - 5;
    if (tempAtk < 1) {
        hero.setAtk(1);
        return;
    }
    hero.setAtk(tempAtk);
}