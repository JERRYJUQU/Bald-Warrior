#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Halfling : public Enemy{
public:
    Halfling(Position pos);
    int defend(Hero & hero) override;
    int attack(Shade & shade) override;
    int attack(Drow & drow) override;
    int attack(Vampire & vampire) override;
    int attack(Troll & troll) override;
    int attack(Goblin & goblin) override;
//    int notifyDeath() override;
};

#endif
