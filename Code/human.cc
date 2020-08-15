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
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+shade.getDef()));
        shade.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}
    
int Human::attack(Drow & drow){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+drow.getDef()));
        drow.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Human::attack(Vampire & vampire){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+vampire.getDef()));
        vampire.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Human::attack(Troll & troll){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+troll.getDef()));
        troll.incHP(-dmg);
        return dmg;
    }else{
        return 0;
    }
}

int Human::attack(Goblin & goblin){
    srand(time(0));
    int miss = std::rand()%2;
    if(!miss){
        int dmg = ((100*(this->getAtk()))/(100+goblin.getDef()));
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
