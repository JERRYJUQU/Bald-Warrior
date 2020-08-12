#include "drow.h"

Drow::Drow(Position pos): Hero{pos, HeroType::drow} {
    hp = 150;
    atk = 25;
    def = 15;
    maxHP = 150;
}

void usePotion(Potion & potion){
    potion.effect(*this);
}

void Drow::defend(Enemy & enemy){
    enemy.attack(*this);
}

void Drow::attack(Human & human){
    human.incHP(-((100/(100+human.getDef()))*(this->getAtk())));
}
        
void Drow::attack(Dwarf & dwarf){
    dwarf.incHP(-((100/(100+dwarf.getDef()))*(this->getAtk())));
}
        
void Drow::attack(Elf & elf){
    elf.incHP(-((100/(100+elf.getDef()))*(this->getAtk())));
}
        
void Drow::attack(Orcs & orcs){
    orcs.incHP(-((100/(100+orcs.getDef()))*(this->getAtk())));
}
        
void Drow::attack(Merchant & merchant){
    merchant.incHP(-((100/(100+merchant.getDef()))*(this->getAtk())));
}
        
void Drow::attack(Dragon & dragon){
    dragon.incHP(-((100/(100+dragon.getDef()))*(this->getAtk())));
}
        
void Drow::defend(Halfling & halfling){
    int miss = std::rand() % 2;
    if(!miss){
        halfling.incHP(-((100/(100+halfling.getDef()))*(this->getAtk())));
    }
}
