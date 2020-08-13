#include "elf.h"

Elf::Elf(Position pos): Hero{pos, EnemyType::elf} {
    hp = 140;
    atk = 30;
    def = 10;
    maxHP = 140;
}
    
void Elf::defend(Hero & hero){
    hero.attack(*this);
}
    
void Elf::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
    miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void Elf::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
    miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void Elf::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
    miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void Elf::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
    miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void Elf::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
    miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
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
