#include "textdisplay.h"
#include "item.h"
#include "subject.h"
#include "floor.h"

Item::Item(Position pos, ItemType type)
	: Subject{pos, ObjType::item}, type{type}
{}

ItemType Item::getItemType(){ return type; };
