#include "troll.h"
Troll::Troll(Position pos): Hero{pos} {
    hp = 120;
    atk = 25;
    def = 15;
    maxHP = 120;
}

void usePotion(Potion & potion){
    potion.effect(*this);
}

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
        
void Troll::defend(Halfling & halfling){
    50%
    halfling.incHP(-((100/(100+halfling.getDef()))*(this->getAtk())));
}

void Troll::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}