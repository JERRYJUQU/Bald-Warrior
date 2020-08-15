#include "poison_health.h"
#include "hero.h"

PoisonHealth::PoisonHealth(Position pos)
    : Potion(pos, PotionType::posionHealth)
{}

void PoisonHealth::effect(Hero &hero) {
    int tempHealth = hero.getHP() - (int)(getScale(hero)*10);
    if (tempHealth < 0) {
        hero.setHP(0);
    }
    else {
        hero.setHP(tempHealth);
    }
}
