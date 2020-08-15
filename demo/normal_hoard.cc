#include "normal_hoard.h"
#include "hero.h"

NormalHoard::NormalHoard(Position pos)
	: Treasure(pos, TreasureType::normal)
{}

void NormalHoard::effect(Hero& hero) {
	hero.incGold(amount);
}