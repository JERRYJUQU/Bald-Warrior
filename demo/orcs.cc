#include "orcs.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"

Orcs::Orcs(Position pos): Enemy{pos, EnemyType::orcs} {
    hp = 180;
    atk = 30;
    def = 25;
    maxHP = 180;
}
    
int Orcs::defend(Hero & hero){
    srand(time(0));
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Orcs::attack(Shade & shade){
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
    
int Orcs::attack(Drow & drow){
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

int Orcs::attack(Vampire & vampire){
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

int Orcs::attack(Troll & troll){
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

int Orcs::attack(Goblin & goblin){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = 1.5*((100*(this->getAtk()))/(100+goblin.getDef()));
        goblin.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
/*
void Orcs::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/
