#include "textdisplay.h"
#include "item.h"
#include "subject.h"
#include "floor.h"

Item::Item(Position pos)
	: Subject{pos, ObjType::item}
{}
