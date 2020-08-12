#include "merchant.h"

Merchant::Merchant(Position pos): Enemy{pos} {
    hp = 30;
    atk = 70;
    def = 5;
    
    neutral = true;
}
    
void Merchant::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void Merchant::attack(Shade & shade){
    shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
}
    
void Merchant::attack(Drow & drow){
    drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
}

void Merchant::attack(Vampire & vampire){
    vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
}

void Merchant::attack(Troll & troll){
    troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
}

void Merchant::attack(Goblin & goblin){
    goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
}

void Merchant::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Merchant::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}
