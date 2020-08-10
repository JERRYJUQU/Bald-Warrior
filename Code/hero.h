#ifndef HERO_H
#define HERO_H
#include "character.h"
#include <string>
using namespace std;

class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;
class Potion;
class Treasure;

class Hero : public Character{
protected:
        int gold;
        int maxHP;
public:
        Hero(Position pos);
        int getGold();
        void incGold(int gold);
        int getMaxHP();
        virtual void defend(Enemy & enemy) = 0;
        virtual void attack(Human & human) = 0;
        virtual void attack(Dwarf & dwarf) = 0;
        virtual void attack(Elf & elf) = 0;
        virtual void attack(Orcs & orcs) = 0;
        virtual void attack(Merchant & merchant) = 0;
        virtual void attack(Dragon & dragon) = 0;
        virtual void attack(Halfling & halfling) = 0;
        virtual void usePotion(Potion & potion);
        void pickUpTreasure(Treasure & treasure);
        void move(string direction);
        virtual void notifyObservers() = 0;
        void notifyDeath();
};

#endif
