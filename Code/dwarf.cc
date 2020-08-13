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
    
void Dwarf::defend(Hero & hero){
    hero.attack(*this);
}

void Dwarf::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void Dwarf::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void Dwarf::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void Dwarf::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void Dwarf::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
}
/*
void Dwarf::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/

