#include "treasure.h"

Treasure::Treasure(int x, int y,
	std::shared_ptr <Observer> display, bool canPickUp)
	: Item(x, y, display),
	canPickUp{canPickUp}
{}

bool Treasure::pickUp() {
	return canPickUp;
}