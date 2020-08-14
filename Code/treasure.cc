#include "treasure.h"
#include "position.h"
#include "item.h"

Treasure::Treasure(Position pos, TreasureType type, bool canPickUp)
	: Item(pos, ItemType::treasure),
	  canPickUp{canPickUp},
		 type{type}
{}

bool Treasure::pickUp() {
	return canPickUp;
}

TreasureType Treasure::getTreasureType() { return type; }
