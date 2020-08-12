#include "halfling.h"

Halfling::Halfling(Position pos): Enemy{pos} {
    hp = 100;
    atk = 15;
    def = 20;
}
    
void Halfling::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void Halfling::attack(Shade & shade){
    shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
}
    
void Halfling::attack(Drow & drow){
    drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
}

void Halfling::attack(Vampire & vampire){
    vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
}

void Halfling::attack(Troll & troll){
    troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
}

void Halfling::attack(Goblin & goblin){
    goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
}

void Halfling::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Halfling::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}