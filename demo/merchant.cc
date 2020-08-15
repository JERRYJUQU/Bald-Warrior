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
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+shade.getDef()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Merchant::attack(Drow & drow){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+drow.getDef()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Merchant::attack(Vampire & vampire){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+vampire.getDef()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Merchant::attack(Troll & troll){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+troll.getDef()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Merchant::attack(Goblin & goblin){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+goblin.getDef()));
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
