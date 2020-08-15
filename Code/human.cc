#include "human.h"
#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "vampire.h"
#include "goblin.h"

Human::Human(Position pos): Enemy{pos, EnemyType::human} {
    hp = 140;
    atk = 20;
    def = 20;
    maxHP = 140;
}
    
int Human::defend(Hero & hero){
    int dmg = hero.attack(*this);
    return dmg;
}
    
int Human::attack(Shade & shade){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+shade.getDef()))*(this->getAtk()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Human::attack(Drow & drow){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+drow.getDef()))*(this->getAtk()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Human::attack(Vampire & vampire){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+vampire.getDef()))*(this->getAtk()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Human::attack(Troll & troll){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+troll.getDef()))*(this->getAtk()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Human::attack(Goblin & goblin){
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100/(100+goblin.getDef()))*(this->getAtk()));
        goblin.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

/*
int Human::notifyDeath(){
    for (auto p : observers){
        p.notifyDeath(*this);
    }
}*/
