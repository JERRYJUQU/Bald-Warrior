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
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Dwarf::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+drow.getDef()))*(this->getAtk()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Dwarf::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Dwarf::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Dwarf::attack(Goblin & goblin){
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
void Dwarf::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/

