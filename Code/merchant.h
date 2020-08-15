#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant : public Enemy{
public:
    Merchant(Position pos);
    int defend(Hero & hero) override;
    int attack(Shade & shade) override;
    int attack(Drow & drow) override;
    int attack(Vampire & vampire) override;
    int attack(Troll & troll) override;
    int attack(Goblin & goblin) override;
};

#endif
