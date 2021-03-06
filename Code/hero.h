#ifndef HERO_H
#define HERO_H
#include "character.h"
enum class HeroType { shade, drow, vampire, troll, goblin };

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
enum class Direction;

class Hero : public Character{
protected:
        int gold;
        HeroType type;
        std::string action;
        int f;//floor level
public:
        Hero(Position pos, HeroType type);
        int getGold();
        void incGold(int gold);
        HeroType getHeroType();
        virtual int defend(Enemy & enemy) = 0;
        virtual int attack(Human & human) = 0;
        virtual int attack(Dwarf & dwarf) = 0;
        virtual int attack(Elf & elf) = 0;
        virtual int attack(Orcs & orcs) = 0;
        virtual int attack(Merchant & merchant) = 0;
        virtual int attack(Dragon & dragon) = 0;
        virtual int attack(Halfling & halfling) = 0;
        void usePotion(Potion & potion);
        void pickUpTreasure(Treasure & treasure);
        void notifyDeath();
        int getFloor();
        void incFloor();
        std::string getAction();
        void setAction(std::string a);
};

#endif
