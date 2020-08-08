#include "wound_def.h"
#include "hero.h"

WoundDef::WoundDef(int x, int y,
    std::shared_ptr <Observer> display)
    : Potion(x, y, display)
{}

void WoundDef::effect(Hero &hero) {
    int tempDef = hero.getDef() + 5;
    if (tempDef < 0) {
        tempDef = 0;
        return;
    }
    hero.setAtk(tempDef);
}