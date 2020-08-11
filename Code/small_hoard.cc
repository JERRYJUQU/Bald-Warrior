#include "small_hoard.h"
#include "hero.h"

SmallHoard::SmallHoard(int x, int y,
	std::shared_ptr <Observer> display)
	: Treasure(x, y, display)
{}

void SmallHoard::effect(Hero& hero) {
	int tempGold = hero.getGold() + amount;
	hero.setGold(tempGold);
}