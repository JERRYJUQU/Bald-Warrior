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
    
int Halfling::attack(Drow & drow){
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

int Halfling::attack(Vampire & vampire){
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

int Halfling::attack(Troll & troll){
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

int Halfling::attack(Goblin & goblin){
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
void Halfling::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/
