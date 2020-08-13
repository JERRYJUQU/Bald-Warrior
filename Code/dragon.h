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
    void defend(Hero & hero) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
//    void notifyDeath() override;
    DragonHoard getHoard();
};


#endif
