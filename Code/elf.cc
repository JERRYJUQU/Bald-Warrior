#include "elf.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"

Elf::Elf(Position pos): Enemy{pos, EnemyType::elf} {
    hp = 140;
    atk = 30;
    def = 10;
    maxHP = 140;
}
    
int Elf::defend(Hero & hero){
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Elf::attack(Shade & shade){
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
    }
    return dmg;
}
    
int Elf::attack(Drow & drow){
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100/(100+drow.getDef()))*(this->getAtk()));
        drow.incHP(-dmg);
    }else{
        dmg = 0;
    }
    return dmg;
}

int Elf::attack(Vampire & vampire){
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
    }
    return dmg;
}

int Elf::attack(Troll & troll){
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
    }
    return dmg;
}

int Elf::attack(Goblin & goblin){
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100/(100+goblin.getDef()))*(this->getAtk()));
        goblin.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100/(100+goblin.getDef()))*(this->getAtk()));
        goblin.incHP(-dmg);
    }
    return dmg;
}
/*
void Elf::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Elf::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}*/
