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
    srand(time(0));
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100*(this->getAtk()))/(100+shade.getDef()));
        shade.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100*(this->getAtk()))/(100+shade.getDef()));
        shade.incHP(-dmg);
    }
    return dmg;
}
    
int Elf::attack(Drow & drow){
    srand(time(0));
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100*(this->getAtk()))/(100+drow.getDef()));
        drow.incHP(-dmg);
    }else{
        dmg = 0;
    }
    return dmg;
}

int Elf::attack(Vampire & vampire){
    srand(time(0));
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100*(this->getAtk()))/(100+vampire.getDef()));
        vampire.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100*(this->getAtk()))/(100+vampire.getDef()));
        vampire.incHP(-dmg);
    }
    return dmg;
}

int Elf::attack(Troll & troll){
    srand(time(0));
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100*(this->getAtk()))/(100+troll.getDef()));
        troll.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100*(this->getAtk()))/(100+troll.getDef()));
        troll.incHP(-dmg);
    }
    return dmg;
}

int Elf::attack(Goblin & goblin){
    srand(time(0));
    int miss = std::rand()%2;
    int dmg;
    if(!miss){
        dmg = ((100*(this->getAtk()))/(100+goblin.getDef()));
        goblin.incHP(-dmg);
    }else{
        dmg = 0;
    }
    miss = std::rand()%2;
    if(!miss){
        dmg += ((100*(this->getAtk()))/(100+goblin.getDef()));
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
