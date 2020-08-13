#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <string>
using namespace std;
enum class EnemyType { human, dwarf, elf, orcs, merchant, dragon, halfling };

class Hero;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
enum class Direction;

class Enemy : public Character{
protected:
        bool neutral;
        EnemyType type;
public:
        Enemy(Position pos, EnemyType type);
        EnemyType getEnemyType();
        virtual void defend(Hero & hero) = 0;
        virtual void attack(Shade & shade) = 0;
        virtual void attack(Drow & drow) = 0;
        virtual void attack(Vampire & vampire) = 0;
        virtual void attack(Troll & troll) = 0;
        virtual void attack(Goblin & goblin) = 0;
        virtual void notifyDeath() = 0;
        //void move(Direction direction);
};

#endif