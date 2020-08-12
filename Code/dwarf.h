#ifndef DWARF_H
#define DWARF_H

class Dwarf : public Enemy{
public:
    Dwarf(Position pos);
    void defend(Hero & hero) override;
    void attack(Shade & shade) override;
    void attack(Drow & drow) override;
    void attack(Vampire & vampire) override;
    void attack(Troll & troll) override;
    void attack(Goblin & goblin) override;
    void notifyDeath() override;
};

#endif
