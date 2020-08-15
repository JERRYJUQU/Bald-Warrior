#include "dragon_hoard.h"
#include "hero.h"

DragonHoard::DragonHoard(Position pos)
	: Treasure(pos, TreasureType::dragonHoard, false)
{}

void DragonHoard::effect(Hero& hero) {
	hero.incGold(amount);
}

void DragonHoard::notifyDeath() {
	canPickUp = true;
}