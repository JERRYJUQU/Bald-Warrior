#include "treasure.h"
#include "position.h"
#include "floor.h"
#include "item.h"

Treasure::Treasure(Position pos, bool canPickUp)
	: Item(pos, ItemType::treasure),
	canPickUp{canPickUp}
{}

bool Treasure::pickUp() {
	return canPickUp;
}
