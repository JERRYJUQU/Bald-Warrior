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
    int miss = std::rand()%1;
    if(!miss){
        shade.incHP(-(this->getAtk()));
    }
}
    
void Human::attack(Drow & drow){
    int miss = std::rand()%1;
    if(!miss){
        drow.incHP(-(this->getAtk()));
    }
}

void Human::attack(Vampire & vampire){
    int miss = std::rand()%1;
    if(!miss){
        vampire.incHP(-(this->getAtk()));
    }
}

void Human::attack(Troll & troll){
    int miss = std::rand()%1;
    if(!miss){
        troll.incHP(-(this->getAtk()));
    }
}

void Human::attack(Goblin & goblin){
    int miss = std::rand()%1;
    if(!miss){
        goblin.incHP(-(this->getAtk()));
    }
}

void Human::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}
