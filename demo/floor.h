#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <ctime>
#include "direction.h"

#include "tile.h"
#include "textdisplay.h"
#include "treasure.h"
#include "hero.h"
#include "enemy.h"
#include "character.h"
#include "item.h"
#include "potion.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

#include "restore_health.h"
#include "boost_atk.h"
#include "boost_def.h"
#include "poison_health.h"
#include "wound_atk.h"
#include "wound_def.h"

#include "dragon_hoard.h"
#include "small_hoard.h"
#include "merchant_hoard.h"
#include "normal_hoard.h"

class Observer;
class Stair;
enum class Action{ use, attack, move };

class Floor {
  int n;
  std::shared_ptr<Hero> hero;
  std::shared_ptr<Stair> stair;
  std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
  std::vector<std::vector<std::shared_ptr<Enemy>>> enemies;
  std::vector<std::vector<std::shared_ptr<Potion>>> potions;
  std::vector<std::vector<std::shared_ptr<Treasure>>> treasures;
  std::shared_ptr<TextDisplay> td;
  bool pause;
  int state;


  std::string map =
  "|-----------------------------------------------------------------------------|\n"
  "|                                                                             |\n"
  "| |--------------------------|        |-----------------------|               |\n"
  "| |..........................|        |.......................|               |\n"
  "| |..........................+########+.......................|-------|       |\n"
  "| |..........................|   #    |...............................|--|    |\n"
  "| |..........................|   #    |..................................|--| |\n"
  "| |----------+---------------|   #    |----+----------------|...............| |\n"
  "|            #                 #############                |...............| |\n"
  "|            #                 #     |-----+------|         |...............| |\n"
  "|            #                 #     |............|         |...............| |\n"
  "|            ###################     |............|   ######+...............| |\n"
  "|            #                 #     |............|   #     |...............| |\n"
  "|            #                 #     |-----+------|   #     |--------+------| |\n"
  "|  |---------+-----------|     #           #          #              #        |\n"
  "|  |.....................|     #           #          #         |----+------| |\n"
  "|  |.....................|     ########################         |...........| |\n"
  "|  |.....................|     #           #                    |...........| |\n"
  "|  |.....................|     #    |------+--------------------|...........| |\n"
  "|  |.....................|     #    |.......................................| |\n"
  "|  |.....................+##########+.......................................| |\n"
  "|  |.....................|          |.......................................| |\n"
  "|  |---------------------|          |---------------------------------------| |\n"
  "|                                                                             |\n"
  "|-----------------------------------------------------------------------------|"; //The map in text form

  //Private methods
  bool guarded(std::shared_ptr<Treasure> treasue);
  Position getNewPos(Position oldPos, Direction dir);
  Position getValidPos(Position pos);
  void refreshDisplay();
  bool heroAround(std::shared_ptr<Enemy> enemy);
  template<typename T> T enumRand();
  void hostileMerchants();
  void seePotions();
  std::string seeAPotion(Potion & potion);
  void revealPotion(Potion & potion);

public:
  Floor(int n);
  void spawn(HeroType ht);
  void enter(std::shared_ptr<Hero> h);
  void moveHero( Direction dir );
  void attackEnemy( Direction dir );
  void usePotion( Direction dir );
  int turn(Action action, Direction dir);
  void setPause();
  std::shared_ptr<Hero> getHero();

  friend std::ostream & operator<<( std::ostream & out, const Floor & f );
};

std::ostream & operator<<( std::ostream & out, const Floor & f );

#endif
