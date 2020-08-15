#include "wound_def.h"
#include "hero.h"

WoundDef::WoundDef(Position pos)
    : Potion(pos, PotionType::woundDef)
{}

void WoundDef::effect(Hero &hero) {
    int tempDef = hero.getDef() - (int) (getScale(hero)*5);
    if (tempDef < 1) {
        tempDef = 0;
        return;
    }
    hero.setDef(tempDef);
}
