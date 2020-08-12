#include "human.h"

Human::Human(Position pos): Enemy{pos, EnemyType::Human} {
    hp = 140;
    atk = 20;
    def = 20;
    maxHP = 140;
}
    
void Human::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void Human::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void Human::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void Human::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void Human::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void Human::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
}


void Human::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}
