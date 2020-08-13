#include "potion.h"
#include "item.h"

Potion::Potion(Position pos, PotionType type)
	: Item(pos, ItemType::potion),
	 type{type}
{}

PotionType Potion::getPotionType() { return type; }
