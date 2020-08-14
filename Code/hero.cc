#include "hero.h"
#include "treasure.h"

Hero::Hero(Position pos, HeroType type):Character{pos, CharacterType::hero}, gold{0}, type{type}, action{"Player character has spawned."}, f{1} {}

int Hero::getGold() { return gold; };
int Hero::getFloor() { return f; };
std::string Hero::getAction() { return action; };

void Hero::incFloor(){
  if(f < 5){
    f++;
  }
};
void Hero::setAction(std::string a) { action = a; };

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
