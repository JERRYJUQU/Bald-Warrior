#include "vampire.h"

Vampire::Vampire(Position pos): Hero{pos, HeroType::vampire} {
    hp = 50;
    atk = 25;
    def = 25;
    maxHP = 10000;
}

void usePotion(Potion & potion){
    potion.effect(*this);
}

void Vampire::defend(Enemy & enemy){
    enemy.attack(*this);
}

void Vampire::attack(Human & human){
    human.incHP(-((100/(100+human.getDef()))*(this->getAtk())));
    hp+=5;
}

void Vampire::attack(Dwarf & dwarf){
    dwarf.incHP(-((100/(100+dwarf.getDef()))*(this->getAtk())));
    hp-=5;
}

void Vampire::attack(Elf & elf){
    elf.incHP(-((100/(100+elf.getDef()))*(this->getAtk())));
    hp+=5;
}

void Vampire::attack(Orcs & orcs){
    orcs.incHP(-((100/(100+orcs.getDef()))*(this->getAtk())));
    hp+=5;
}

void Vampire::attack(Merchant & merchant){
    merchant.incHP(-((100/(100+merchant.getDef()))*(this->getAtk())));
    hp+=5;
}

void Vampire::attack(Dragon & dragon){
    dragon.incHP(-((100/(100+dragon.getDef()))*(this->getAtk())));
    hp+=5;
}

void Vampire::defend(Halfling & halfling){
    int miss = std::rand() % (1);
    if(!miss){
        halfling.incHP(-((100/(100+halfling.getDef()))*(this->getAtk())));
        hp+=5;
    }    
}

void Vampire::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}
