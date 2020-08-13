#include "treasure.h"
#include "position.h"
#include "floor.h"
#include "item.h"

Treasure::Treasure(Position pos, TreasureType type, bool canPickUp)
	: Item(pos, ItemType::treasure),
	  type{type},
	  canPickUp{canPickUp}
{}

bool Treasure::pickUp() {
	return canPickUp;
}

TreasureType Treasure::getTreasureType() { return type; }