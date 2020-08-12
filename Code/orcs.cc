#include "orcs.h"

Orcs::Orcs(Position pos): Enemy{pos, EnemyType::orcs} {
    hp = 180;
    atk = 30;
    def = 25;
    maxHP = 180;
}
    
void Orcs::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void  Orcs::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void  Orcs::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void  Orcs::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void  Orcs::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void  Orcs::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-1.5*((100/(100+goblin.getDef()))*(this->getAtk())));
    }
}

void Orcs::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}
