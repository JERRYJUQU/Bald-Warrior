#ifndef DROW_H
#define DROW_H
#include "hero.h"

class Drow : public Hero{
    public:
        Drow(Position pos);
//         int usePotion(Potion & potion) override;
         int defend(Enemy & enemy) override;
         int attack(Human & human) override;
         int attack(Dwarf & dwarf) override;
         int attack(Elf & elf) override;
         int attack(Orcs & orcs) override;
         int attack(Merchant & merchant) override;
         int attack(Dragon & dragon) override;
         int attack(Halfling & halfling) override;
};

#endif
