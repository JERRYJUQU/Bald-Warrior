#include "troll.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

Troll::Troll(Position pos): Hero{pos, HeroType::troll} {
    hp = 120;
    atk = 25;
    def = 15;
    maxHP = 120;
}
/*
 int usePotion(Potion & potion){
    potion.effect(*this);
}*/

 int Troll::defend(Enemy & enemy){
    int dmg = enemy.attack(*this);
    return dmg;
}

 int Troll::attack(Human & human){
    int dmg = ((100*(this->getAtk()))/(100+human.getDef()));
    human.incHP(-dmg);
    return dmg; 
}
        
 int Troll::attack(Dwarf & dwarf){
    int dmg = ((100*(this->getAtk()))/(100+dwarf.getDef()));
    dwarf.incHP(-dmg);
    return dmg; 
}
        
 int Troll::attack(Elf & elf){
    int dmg = ((100*(this->getAtk()))/(100+elf.getDef()));
    elf.incHP(-dmg);
    return dmg; 
}
        
 int Troll::attack(Orcs & orcs){
    int dmg = ((100*(this->getAtk()))/(100+orcs.getDef()));
    orcs.incHP(-dmg);
    return dmg; 
}
        
 int Troll::attack(Merchant & merchant){
    int dmg = ((100*(this->getAtk()))/(100+merchant.getDef()));
    merchant.incHP(-dmg);
    return dmg; 
}
        
 int Troll::attack(Dragon & dragon){
    int dmg = ((100*(this->getAtk()))/(100+dragon.getDef()));
    dragon.incHP(-dmg);
    return dmg; 
}
        
 int Troll::attack(Halfling & halfling){
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

