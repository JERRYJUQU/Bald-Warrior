#include "merchant_hoard.h"
#include "hero.h"

MerchantHoard::MerchantHoard(int x, int y,
	std::shared_ptr <Observer> display)
	: Treasure(x, y, display)
{}

void MerchantHoard::effect(Hero& hero) {
	int tempGold = hero.getGold() + amount;
	hero.setGold(tempGold);
}