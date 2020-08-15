#include "dragon.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"
#include "dragon_hoard.h"
Dragon::Dragon(Position pos, shared_ptr<DragonHoard> hoard): Enemy{pos, EnemyType::dragon}, hoard{hoard}{
    hp = 150;
    atk = 20;
    def = 20;
    maxHP = 150;
}

int Dragon::defend(Hero & hero){
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Dragon::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Dragon::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+drow.getDef()))*(this->getAtk()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Dragon::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Dragon::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Dragon::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+goblin.getDef()))*(this->getAtk()));
        goblin.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

void Dragon::notifyHoard(){
    hoard->notifyDeath();
}

DragonHoard Dragon::getHoard(){return *hoard;}
