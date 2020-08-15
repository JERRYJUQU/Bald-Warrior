#ifndef ORCS_H
#define ORCS_H
#include "enemy.h"

class Orcs : public Enemy{
public:
    Orcs(Position pos);
    int defend(Hero & hero) override;
    int attack(Shade & shade) override;
    int attack(Drow & drow) override;
    int attack(Vampire & vampire) override;
    int attack(Troll & troll) override;
    int attack(Goblin & goblin) override;
//    int notifyDeath() override;
};

#endif
