#include "merchant_hoard.h"
#include "hero.h"

MerchantHoard::MerchantHoard(Position pos)
	: Treasure(pos, TreasureType::merchantHoard)
{}

void MerchantHoard::effect(Hero& hero) {
	int tempGold = hero.getGold() + amount;
	hero.incGold(amount);
}