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
void usePotion(Potion & potion){
    potion.effect(*this);
}*/

void Troll::defend(Enemy & enemy){
    enemy.attack(*this);
}

void Troll::attack(Human & human){
    human.incHP(-((100/(100+human.getDef()))*(this->getAtk())));
}
        
void Troll::attack(Dwarf & dwarf){
    dwarf.incHP(-((100/(100+dwarf.getDef()))*(this->getAtk())));
}
        
void Troll::attack(Elf & elf){
    elf.incHP(-((100/(100+elf.getDef()))*(this->getAtk())));
}
        
void Troll::attack(Orcs & orcs){
    orcs.incHP(-((100/(100+orcs.getDef()))*(this->getAtk())));
}
        
void Troll::attack(Merchant & merchant){
    merchant.incHP(-((100/(100+merchant.getDef()))*(this->getAtk())));
}
        
void Troll::attack(Dragon & dragon){
    dragon.incHP(-((100/(100+dragon.getDef()))*(this->getAtk())));
}
        
void Troll::attack(Halfling & halfling){
    int miss = std::rand() % 2;
    if(!miss){
        halfling.incHP(-((100/(100+halfling.getDef()))*(this->getAtk())));
    }
}

