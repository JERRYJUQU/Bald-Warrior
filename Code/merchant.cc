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
    
int Merchant::defend(Hero & hero){
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Merchant::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Merchant::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+drow.getDef()))*(this->getAtk()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Merchant::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Merchant::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Merchant::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+goblin.getDef()))*(this->getAtk()));
        goblin.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
/*
void Merchant::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/
