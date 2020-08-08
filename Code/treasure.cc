#include "treasure.h"

Treasure::Treasure(int x, int y,
	std::shared_ptr <Observer> display)
	: Item(x, y, display)
{}