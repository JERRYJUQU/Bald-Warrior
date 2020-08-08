#include "text_display.h"
#include "item.h"

Item::Item(int x, int y,
	std::shared_ptr <Observer> display)
	: pos{x, y},
	  display{display}
{}

Position Item::getPosition() {
	return pos;
}

void Item::notify() {
	display->notify(this);
}