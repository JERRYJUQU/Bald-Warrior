#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include <memory>
#include "dragon_hoard.h"
class DragonHoard;

class Dragon : public Enemy{
	std::shared_ptr<DragonHoard> hoard;
public:
    Dragon(Position pos, shared_ptr<DragonHoard> hoard);
    int defend(Hero & hero) override;
    int attack(Shade & shade) override;
    int attack(Drow & drow) override;
    int attack(Vampire & vampire) override;
    int attack(Troll & troll) override;
    int attack(Goblin & goblin) override;
//    void notifyDeath() override;
    DragonHoard getHoard();
    void notifyHoard();
};


#endif
