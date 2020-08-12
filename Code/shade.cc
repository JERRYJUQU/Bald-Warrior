#include "shade.h"
Shade::Shade(Position pos): Hero{pos, HeroType::shade} {
    hp = 125;
    atk = 25;
    def = 25;
    maxHP = 125;
}

void usePotion(Potion & potion){
    potion.effect(*this);
}

void Shade::defend(Enemy & enemy){
    enemy.attack(*this);
}

void Shade::attack(Human & human){
    human.incHP(-((100/(100+human.getDef()))*(this->getAtk())));
}
        
void Shade::attack(Dwarf & dwarf){
    dwarf.incHP(-((100/(100+dwarf.getDef()))*(this->getAtk())));
}
        
void Shade::attack(Elf & elf){
    elf.incHP(-((100/(100+elf.getDef()))*(this->getAtk())));
}
        
void Shade::attack(Orcs & orcs){
    orcs.incHP(-((100/(100+orcs.getDef()))*(this->getAtk())));
}
        
void Shade::attack(Merchant & merchant){
    merchant.incHP(-((100/(100+merchant.getDef()))*(this->getAtk())));
}
        
void Shade::attack(Dragon & dragon){
    dragon.incHP(-((100/(100+dragon.getDef()))*(this->getAtk())));
}
        
void Shade::defend(Halfling & halfling){
    int miss = rand() % (1);
    if(!miss){
        halfling.incHP(-((100/(100+halfling.getDef()))*(this->getAtk())));
    }
}

void Shade::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}
