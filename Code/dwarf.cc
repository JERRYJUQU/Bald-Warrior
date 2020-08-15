#include "dwarf.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"

Dwarf::Dwarf(Position pos): Enemy{pos, EnemyType::dwarf} {
    hp = 100;
    atk = 20;
    def = 30;
    maxHP = 100;
    
}
    
int Dwarf::defend(Hero & hero){
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Dwarf::attack(Shade & shade){
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
    
int Dwarf::attack(Drow & drow){
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

int Dwarf::attack(Vampire & vampire){
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

int Dwarf::attack(Troll & troll){
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

int Dwarf::attack(Goblin & goblin){
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
void Dwarf::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/

