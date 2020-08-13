#ifndef DROW_H
#define DROW_H
#include "hero.h"

class Drow : public Hero{
    public:
        Drow(Position pos);
//        void usePotion(Potion & potion) override;
        void defend(Enemy & enemy) override;
        void attack(Human & human) override;
        void attack(Dwarf & dwarf) override;
        void attack(Elf & elf) override;
        void attack(Orcs & orcs) override;
        void attack(Merchant & merchant) override;
        void attack(Dragon & dragon) override;
        void attack(Halfling & halfling) override;
};

#endif
