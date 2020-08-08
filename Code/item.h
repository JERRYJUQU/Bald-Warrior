#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <memory>
#include "position.h"

class Observer;
class Hero;

class Item {
	Position pos;
	std::shared_ptr <Observer> display;

public:
	Item(int x, int y, 
		std::shared_ptr <Observer> display);
	virtual void effect(std::shared_ptr <Hero> hero) = 0;
	Position getPosition();
	void notify();
};

#endif