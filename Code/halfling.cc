#include "halfling.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"

Halfling::Halfling(Position pos): Enemy{pos, EnemyType::halfling} {
    hp = 100;
    atk = 15;
    def = 20;
    hp = 100;
}
    
int Halfling::defend(Hero & hero){
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Halfling::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Halfling::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+drow.getDef()))*(this->getAtk()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Halfling::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Halfling::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Halfling::attack(Goblin & goblin){
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
void Halfling::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/
