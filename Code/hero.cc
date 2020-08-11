#include "hero.h"

Hero::Hero(Position pos):Character{pos}, gold{0}, maxHP{0} {}

int Hero::getGold() return gold;
int Hero::getMaxHP() return maxHP;
void Hero::incGold(int gold){
        this->gold += gold;
}
void Hero::pickUpTreasure(Treasure & treasure){
        treasure.effect(*this);
}
void move(string direction){
        if(direction == "no"){
                pos.y -= 1;
        }else if(direction == "so"){
                pos.y += 1;
        }else if(direction == "ea"){
                pos.x += 1;
        }else if(direction == "we"){
                pos.x -= 1;
        }else if(direction == "ne"){
                pos.x += 1;
                pos.y -= 1;
        }else if(direction == "nw"){
                pos.x -= 1;
                pos.y -= 1;
        }else if(direction == "se"){
                pos.x += 1;
                pos.y += 1;
        }else if(direction == "sw"){
                pos.x -= 1;
                pos.y += 1;
        }
}

void Hero::notifyDeath(){
        for(auto p : observers){
                p.notifyDeath(*this);
        }
}