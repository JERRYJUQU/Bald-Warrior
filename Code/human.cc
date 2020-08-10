#include "human.h"

Human::Human(Position pos): Enemy{pos} {
    hp = 140;
    atk = 20;
    def = 20;
}
    
void Human::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void Human::attack(Shade & shade){
    shade.incHP(-(this->getAtk()));
}
    
void Human::attack(Drow & drow){
    drow.incHP(-(this->getAtk()));
}

void Human::attack(Vampire & vampire){
    vampire.incHP(-(this->getAtk()));
}

void Human::attack(Troll & troll){
    troll.incHP(-(this->getAtk()));
}

void Human::attack(Goblin & goblin){
    goblin.incHP(-(this->getAtk()));
}

void Human::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Human::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}