#include "merchant.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"

Merchant::Merchant(Position pos): Enemy{pos, EnemyType::merchant} {
    hp = 30;
    atk = 70;
    def = 5;
    maxHP = 30;
    neutral = true;
}
    
void Merchant::defend(Hero & hero){
    hero.attack(*this);
}
    
void  Merchant::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void  Merchant::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void  Merchant::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void  Merchant::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void  Merchant::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
}
/*
void Merchant::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/
