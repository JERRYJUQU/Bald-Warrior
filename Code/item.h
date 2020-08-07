#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <memory>
#include "position.h"
class Observer;
class Hero;

class Item {
	Position pos;
	std::vector <std::shared_ptr <Observer>> observers;

public:
	Item(int x, int y);
	virtual void effect(std::shared_ptr<Hero> hero) = 0;
	Position getPosition();
	void attach(std::shared_ptr <Observer> observer);
	void detach(std::shared_ptr <Observer> observer);
	void notify(std::shared_ptr <Observer> observer);
};

#endif