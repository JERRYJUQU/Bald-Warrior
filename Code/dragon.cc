#include "dragon.h"

Dragon::Dragon(Position pos, shared_ptr<DragonHoard> hoard): Enemy{pos}, hoard{hoard}{
    hp = 150;
    atk = 20;
    def = 20;
    maxHP = 150;
}

void Dragon::defend(Enemy & enemy){
    enemy.attack(*this);
}
    
void  Dragon::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        shade.incHP(-((100/(100+shade.getDef()))*(this->getAtk())));
    }
}
    
void  Dragon::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        drow.incHP(-((100/(100+drow.getDef()))*(this->getAtk())));
    }
}

void  Dragon::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        vampire.incHP(-((100/(100+vampire.getDef()))*(this->getAtk())));
    }
}

void  Dragon::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        troll.incHP(-((100/(100+troll.getDef()))*(this->getAtk())));
    }
}

void  Dragon::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        goblin.incHP(-((100/(100+goblin.getDef()))*(this->getAtk())));
    }
}

void Dragon::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
    hoard->notifyDeath();
}

DragonHoard Dragon::getHoard(){return *hoard;}
