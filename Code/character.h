#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <memory>
#include "position.h"
#include "subject.h"
using namespace std;
enum class CharacterType { hero, enemy };

class Observer;
enum class Direction;

class Character : public Subject{
protected:
        Position pos;
        CharacterType type;
        int hp, atk, def;
        vector<shared_ptr<Observer>> observers;
public:
        Character(Position pos, CharacterType type);
        Position getPos();
        int getHP();
        int getAtk();
        int getDef();
        virtual int getMaxHP() = 0;
        void incHP(int hp);
        void setHP(int hp);
        void setAtk(int atk);
        void setDef(int def);
        void attach(shared_ptr<Observer> observer);
        void move(Direction dir);
        CharacterType getCharacterType();
};

#endif
