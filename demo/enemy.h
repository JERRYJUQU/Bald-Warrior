#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <string>
using namespace std;
enum class EnemyType { human, dwarf, elf, orcs, merchant, dragon, halfling };
static std::string etos( EnemyType type ){
  switch(type){
  case EnemyType::human: return "H";
  case EnemyType::dwarf: return "W";
  case EnemyType::elf: return "E";
  case EnemyType::orcs: return "O";
  case EnemyType::merchant: return "M";
  case EnemyType::dragon: return "D";
  case EnemyType::halfling: return "L";
  }
}

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
        bool getNeutral();
        void setNeutral(bool n);
        virtual int defend(Hero & hero) = 0;
        virtual int attack(Shade & shade) = 0;
        virtual int attack(Drow & drow) = 0;
        virtual int attack(Vampire & vampire) = 0;
        virtual int attack(Troll & troll) = 0;
        virtual int attack(Goblin & goblin) = 0;
        void notifyDeath();
        //void move(Direction direction);
};

#endif
