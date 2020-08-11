#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <string>
using namespace std;

class Hero;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Enemy : public Character{
protected:
        bool neutral;
public:
        Enemy(Position pos);
        virtual void defend(Hero & hero) = 0;
        virtual void attack(Shade & shade) = 0;
        virtual void attack(Drow & drow) = 0;
        virtual void attack(Vampire & vampire) = 0;
        virtual void attack(Troll & troll) = 0;
        virtual void attack(Goblin & goblin) = 0;
        virtual void notifyDeath() = 0;
        void move(string direction);
        virtual void notifyObservers() = 0;
};

#endif