#include "normal_hoard.h"
#include "hero.h"

NormalHoard::NormalHoard(int x, int y,
	std::shared_ptr <Observer> display)
	: Treasure(x, y, display)
{}

void NormalHoard::effect(Hero& hero) {
	int tempGold = hero.getGold() + amount;
	hero.setGold(tempGold);
}