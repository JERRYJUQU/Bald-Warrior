#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <memory>
#include "position.h"
#include "subject.h"

enum class CharacterType { hero, enemy };

class Observer;

class Character : public Subject{
protected:
        CharacterType type;
        int hp, atk, def, maxHP;
public:
        Character(Position pos, CharacterType type);
        Position getPos();
        int getHP();
        int getAtk();
        int getDef();
        int getMaxHP();
        void incHP(int hp);
        void setHP(int hp);
        void setAtk(int atk);
        void setDef(int def);
        CharacterType getCharacterType();

};

#endif
