#include "restore_health.h"
#include "hero.h"

RestoreHealth::RestoreHealth(int x, int y,
    std::shared_ptr <Observer> display)
    : Potion(x, y, display)
{}

void RestoreHealth::effect(Hero &hero) {
    int tempHealth = hero.getHP() + 10;
    if (tempHealth > hero.getMaxHP()) {
        hero.setHP(hero.getMaxHP());
    }
    else {
        hero.setHP(tempHealth);
    }
}