#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <memory>
using namespace std;

class Position;
class Observer;

class Character{
protected:
        Posistion pos;
        int hp, atk, def;
        vector<shared_ptr<Observer>> observers;
public:
        Character(Position pos);
        Position getPos();
        int getHP();
        int getAtk();
        int getDef();
        void incHP(int hp);
        void setHP(int hp);
        void setAtk(int atk);
        void setDef(int def);
        void attach(shared_ptr<Observer> observer);
};

#endif
