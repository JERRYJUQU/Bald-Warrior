#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <memory>
#include "position.h"
#include "subject.h"

class Observer;
class Hero;
enum class ItemType { treasure, potion };

class Item : public Subject{
	ItemType type;

public:
	Item(Position pos, ItemType type);
	ItemType getItemType();
	virtual void effect(Hero & hero) = 0;
};

#endif
