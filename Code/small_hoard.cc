#include "small_hoard.h"
#include "hero.h"

SmallHoard::SmallHoard(Position pos)
	: Treasure(pos, TreasureType::small)
{}

void SmallHoard::effect(Hero& hero) {
	hero.incGold(amount);
}