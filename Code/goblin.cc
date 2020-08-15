#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

Goblin::Goblin(Position pos): Hero{pos, HeroType::goblin} {
    hp = 110;
    atk = 15;
    def = 20;
    maxHP = 110;
}
/*
void usePotion(Potion & potion){
    potion.effect(*this);
}*/

int Goblin::defend(Enemy & enemy){
    int dmg = enemy.attack(*this);
    return dmg;
}

 int Goblin::attack(Human & human){
    int dmg = ((100/(100+human.getDef()))*(this->getAtk()));
    human.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Dwarf & dwarf){
    int dmg = ((100/(100+dwarf.getDef()))*(this->getAtk()));
    dwarf.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Elf & elf){
    int dmg = ((100/(100+elf.getDef()))*(this->getAtk()));
    elf.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Orcs & orcs){
    int dmg = ((100/(100+orcs.getDef()))*(this->getAtk()));
    orcs.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Merchant & merchant){
    int dmg = ((100/(100+merchant.getDef()))*(this->getAtk()));
    merchant.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Dragon & dragon){
    int dmg = ((100/(100+dragon.getDef()))*(this->getAtk()));
    dragon.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Halfling & halfling){
    int miss = std::rand() % 2;
    if(!miss){
        int dmg = ((100/(100+halfling.getDef()))*(this->getAtk()));
        halfling.incHP(-dmg);
        return dmg; 
    }else{
        return 0;
    }
}

