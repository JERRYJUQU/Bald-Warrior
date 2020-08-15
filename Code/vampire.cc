#include "vampire.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

Vampire::Vampire(Position pos): Hero{pos, HeroType::vampire} {
    hp = 50;
    atk = 25;
    def = 25;
    maxHP = 10000;
}
/*
void usePotion(Potion & potion){
    potion.effect(*this);
}*/

int Vampire::defend(Enemy & enemy){
    int dmg = enemy.attack(*this);
    return dmg;
}

 int Vampire::attack(Human & human){
    int dmg = ((100/(100+human.getDef()))*(this->getAtk()));
    human.incHP(-dmg);
    hp+=5;
    return dmg; 
}
        
 int Vampire::attack(Dwarf & dwarf){
    int dmg = ((100/(100+dwarf.getDef()))*(this->getAtk()));
    dwarf.incHP(-dmg);
    hp-=5;
    return dmg; 
}
        
 int Vampire::attack(Elf & elf){
    int dmg = ((100/(100+elf.getDef()))*(this->getAtk()));
    elf.incHP(-dmg);
    hp+=5;
    return dmg; 
}
        
 int Vampire::attack(Orcs & orcs){
    int dmg = ((100/(100+orcs.getDef()))*(this->getAtk()));
    orcs.incHP(-dmg);
    hp+=5;
    return dmg; 
}
        
 int Vampire::attack(Merchant & merchant){
    int dmg = ((100/(100+merchant.getDef()))*(this->getAtk()));
    merchant.incHP(-dmg);
    hp+=5;
    return dmg; 
}
        
 int Vampire::attack(Dragon & dragon){
    int dmg = ((100/(100+dragon.getDef()))*(this->getAtk()));
    dragon.incHP(-dmg);
    hp+=5;
    return dmg; 
}
        
 int Vampire::attack(Halfling & halfling){
    int miss = std::rand() % 2;
    if(!miss){
        int dmg = ((100/(100+halfling.getDef()))*(this->getAtk()));
        halfling.incHP(-dmg);
        hp+=5;
        return dmg; 
    }else{
        return 0;
    }
}