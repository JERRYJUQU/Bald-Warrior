#include "dragon_hoard.h"
#include "hero.h"

DragonHoard::DragonHoard(int x, int y,
	std::shared_ptr <Observer> display)
	: Treasure(x, y, display, false)
{}

void DragonHoard::effect(Hero& hero) {
	int tempGold = hero.getGold() + amount;
	hero.setGold(tempGold);
}

void DragonHoard::notifyDeath() {
	canPickUp = true;
}