#include "orcs.h"

Orcs::Orcs(Position pos): Enemy{pos} {
    hp = 180;
    atk = 30;
    def = 25;
}
    
void Orcs::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void Orcs::attack(Shade & shade){
    shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
}
    
void Orcs::attack(Drow & drow){
    drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
}

void Orcs::attack(Vampire & vampire){
    vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
}

void Orcs::attack(Troll & troll){
    troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
}

void Orcs::attack(Goblin & goblin){
    goblin.incHP(-1.5((100/(100+goblin.getDef()))*(this->getAtk())));
}

void Orcs::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Orcs::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}