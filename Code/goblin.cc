#include "goblin.h"
Goblin::Goblin(Position pos): Hero{pos} {
    hp = 110;
    atk = 15;
    def = 20;
    maxHP = 110;
}

void usePotion(Potion & potion){
    potion.effect(*this);
}

void Goblin::defend(Enemy & enemy){
    enemy.attack(*this);
}

void Goblin::attack(Human & human){
    human.incHP(-((100/(100+human.getDef()))*(this->getAtk())));
}
        
void Goblin::attack(Dwarf & dwarf){
    dwarf.incHP(-((100/(100+dwarf.getDef()))*(this->getAtk())));
}
        
void Goblin::attack(Elf & elf){
    elf.incHP(-((100/(100+elf.getDef()))*(this->getAtk())));
}
        
void Goblin::attack(Orcs & orcs){
    orcs.incHP(-((100/(100+orcs.getDef()))*(this->getAtk())));
}
        
void Goblin::attack(Merchant & merchant){
    merchant.incHP(-((100/(100+merchant.getDef()))*(this->getAtk())));
}
        
void Goblin::attack(Dragon & dragon){
    dragon.incHP(-((100/(100+dragon.getDef()))*(this->getAtk())));
}
        
void Goblin::defend(Halfling & halfling){
    50%
    halfling.incHP(-((100/(100+halfling.getDef()))*(this->getAtk())));
}

void Goblin::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}