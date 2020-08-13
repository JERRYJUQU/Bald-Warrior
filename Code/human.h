#ifndef HUMAN_H
#define HUMAN_H
#include "enemy.h"

class Human : public Enemy{
public:
    Human(Position pos);
    void defend(Hero & hero) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
//    void notifyDeath() override;
};

#endif
