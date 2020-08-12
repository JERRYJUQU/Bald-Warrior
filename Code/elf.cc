#include "elf.h"

Elf::Elf(Position pos): Hero{pos} {
    hp = 140;
    atk = 30;
    def = 10;
}
    
void Elf::defend(Hero & hero){
    hero.attack(*this);
}
    
void Elf::attack(Shade & shade){
    shade.incHP(-2*((100/(100+shade.getDef()))*(this->getAtk())));
}
    
void Elf::attack(Drow & drow){
    drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
}

void Elf::attack(Vampire & vampire){
    vampire.incHP(-2*((100/(100+vampire.getDef()))*(this->getAtk())));
}

void Elf::attack(Troll & troll){
    troll.incHP(-2*((100/(100+troll.getDef()))*(this->getAtk())));
}

void Elf::attack(Goblin & goblin){
    goblin.incHP(-2*((100/(100+goblin.getDef()))*(this->getAtk())));
}

void Elf::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Elf::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}