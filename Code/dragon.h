#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include <memory>
using namespace std;
class DrgonHoard;

class Dragon : public Enemy{
    shared_ptr<DragonHoard> hoard;
public:
    Dragon(Position pos, shared_ptr<DragonHoard> hoard);
    void defend(Enemy & enemy) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
    void notifyDeath() override;
    void notifyObservers() override;
};

#endif