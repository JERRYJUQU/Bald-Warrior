#include "restore_health.h"
#include "hero.h"

RestoreHealth::RestoreHealth(Position pos)
    : Potion(pos, PotionType::restoreHealth)
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