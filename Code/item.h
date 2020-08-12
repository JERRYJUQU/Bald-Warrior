#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <memory>
#include "position.h"
#include "subject.h"

class Observer;
class Hero;

class Item : public Subject{
	Position pos;

public:
	Item(Position pos);
	virtual void effect(std::shared_ptr <Hero> hero) = 0;
};

#endif
