#include "treasure.h"
#include "position.h"
#include "floor.h"

Treasure::Treasure(Position pos, bool canPickUp)
	: Item(pos),
	canPickUp{canPickUp}
{}

bool Treasure::pickUp() {
	return canPickUp;
}
