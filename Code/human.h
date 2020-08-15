#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human : public Enemy{
public:
    Human(Position pos);
    int defend(Hero & hero) override;
    int attack(Shade & shade) override;
    int attack(Drow & drow) override;
    int attack(Vampire & vampire) override;
    int attack(Troll & troll) override;
    int attack(Goblin & goblin) override;
//    int notifyDeath() override;
};

#endif
