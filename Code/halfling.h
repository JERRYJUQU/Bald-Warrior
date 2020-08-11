#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Halfling : public Enemy{
public:
    Halfling(Position pos);
    void defend(Enemy & enemy) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
    void notifyDeath() override;
    void notifyObservers() override;
};

#endif