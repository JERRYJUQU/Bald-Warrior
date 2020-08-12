#include "halfling.h"

Halfling::Halfling(Position pos): Enemy{pos} {
    hp = 100;
    atk = 15;
    def = 20;
    hp = 100;
}
    
void Halfling::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void  Halfling::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void  Halfling::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void  Halfling::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void  Halfling::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void  Halfling::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
}

void Halfling::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}
