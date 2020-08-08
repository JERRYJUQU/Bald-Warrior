#include "poison_health.h"
#include "hero.h"

PoisonHealth::PoisonHealth(int x, int y,
    std::shared_ptr <Observer> display)
    : Potion(x, y, display)
{}

void PoisonHealth::effect(Hero &hero) {
    int tempHealth = hero.getHP() - 10;
    if (tempHealth < 0) {
        hero.setHP(tempHealth + 10);
    }
    else {
        hero.setHP(tempHealth);
    }
}