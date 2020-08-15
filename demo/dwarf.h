#ifndef DWARF_H
#define DWARF_H
#include "enemy.h"

class Dwarf : public Enemy{
public:
    Dwarf(Position pos);
    int defend(Hero & hero) override;
    int attack(Shade & shade) override;
    int attack(Drow & drow) override;
    int attack(Vampire & vampire) override;
    int attack(Troll & troll) override;
    int attack(Goblin & goblin) override;
//    int notifyDeath() override;
};

#endif
