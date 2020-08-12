#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant : public Enemy{
public:
    Merchant(Position pos);
    void defend(Enemy & enemy) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
};

#endif
