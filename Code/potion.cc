#include "potion.h"
#include "item.h"
#include "hero.h"

Potion::Potion(Position pos, PotionType type)
	: Item(pos, ItemType::potion),
	 type{type}, used{false}
{}
double Potion::getScale(Hero &hero){
	if(hero.getHeroType() == HeroType::drow){
		return 1.5;
	}else{
		return 1;
	}
};

void Potion::setUsed(bool b){
	used = b;
};

bool Potion::getUsed(){
	return used;
};

PotionType Potion::getPotionType() { return type; }
