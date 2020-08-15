#include "potion.h"
#include "item.h"
#include "hero.h"

Potion::Potion(Position pos, PotionType type)
	: Item(pos, ItemType::potion),
	 type{type}
{}
double Potion::getScale(Hero &hero){
	if(hero.getHeroType() == HeroType::drow){
		return 1.5;
	}else{
		return 1;
	}
};

PotionType Potion::getPotionType() { return type; }
