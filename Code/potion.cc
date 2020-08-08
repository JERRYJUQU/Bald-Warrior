#include "potion.h"

Potion::Potion(int x, int y, 
	std::shared_ptr <Observer> display) 
	: Item(x, y, display)
{}