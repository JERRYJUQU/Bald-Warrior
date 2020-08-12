#ifndef ORCS_H
#define ORCS_H
#include "enemy.h"

class Orcs : public Enemy{
public:
    Orcs(Position pos);
    void defend(Enemy & enemy) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
    void notifyDeath() override;
};

#endif
