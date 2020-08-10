#include "dragon.h"

Dragon::Dragon(Position pos, shared_ptr<DragonHoard> hoard): Enemy{pos}, hoard{hoard}{
    hp = 150;
    atk = 20;
    def = 20;
}

void Dragon::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void Dragon::attack(Shade & shade){
    shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
}
    
void Dragon::attack(Drow & drow){
    drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
}

void Dragon::attack(Vampire & vampire){
    vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
}

void Dragon::attack(Troll & troll){
    troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
}

void Dragon::attack(Goblin & goblin){
    goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
}

void Dragon::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
    hoard->notifyDeath();
}

void Dragon::notifyObservers(){
        for(auto p:observers){
                p.notify(*this);
        }
        return;
}