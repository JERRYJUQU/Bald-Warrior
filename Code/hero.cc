#include "hero.h"
#include "treasure.h"

Hero::Hero(Position pos, HeroType type):Character{pos, CharacterType::hero}, gold{0}, type{type} {}

int Hero::getGold() { return gold; };
void Hero::incGold(int gold){
        this->gold += gold;
}
HeroType Hero::getHeroType(){ return type; };
void Hero::pickUpTreasure(Treasure & treasure){
        treasure.effect(*this);
}

void Hero::usePotion(Potion & potion){

};
void Hero::notifyDeath(){
        /*for(auto p : observers){
                p->notifyDeath(*this);
        }*/
}
