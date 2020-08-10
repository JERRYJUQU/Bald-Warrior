#include "dwarf.h"

Dwarf::Dwarf(Position pos): Hero{pos} {
    hp = 100;
    atk = 20;
    def = 30;
}
    
void Dwarf::defend(Hero & hero){
    hero.attack(*this);
}

void Dwarf::attack(Shade & shade){
    shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
}
    
void Dwarf::attack(Drow & drow){
    drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
}

void Dwarf::attack(Vampire & vampire){
    vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
}

void Dwarf::attack(Troll & troll){
    troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
}

void Dwarf::attack(Goblin & goblin){
    goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
}

void Dwarf::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}

void Dwarf::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}