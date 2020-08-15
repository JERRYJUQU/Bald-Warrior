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
    int dmg = ((100*(this->getAtk()))/(100+human.getDef()));
    human.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Dwarf & dwarf){
    int dmg = ((100*(this->getAtk()))/(100+dwarf.getDef()));
    dwarf.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Elf & elf){
    int dmg = ((100*(this->getAtk()))/(100+elf.getDef()));
    elf.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Orcs & orcs){
    int dmg = ((100*(this->getAtk()))/(100+orcs.getDef()));
    orcs.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Merchant & merchant){
    int dmg = ((100*(this->getAtk()))/(100+merchant.getDef()));
    merchant.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Dragon & dragon){
    int dmg = ((100*(this->getAtk()))/(100+dragon.getDef()));
    dragon.incHP(-dmg);
    return dmg; 
}
        
 int Goblin::attack(Halfling & halfling){
    srand(time(0));
    int miss = std::rand() % 2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+halfling.getDef()));
        halfling.incHP(-dmg);
        return dmg; 
    }else{
        return 0;
    }
}

