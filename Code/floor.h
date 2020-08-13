#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
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

class Floor {
  std::string name;
  std::shared_ptr<Hero> hero;
  std::shared_ptr<Stair> stair;
  std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
  std::vector<std::vector<std::shared_ptr<Enemy>>> enemies;
  std::vector<std::vector<std::shared_ptr<Potion>>> potions;
  std::vector<std::vector<std::shared_ptr<Treasure>>> treasures;
  std::shared_ptr<TextDisplay> td;


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
  bool checkCollision(Position pos, std::string type);
  bool guarded(std::shared_ptr<Treasure> treasue);
  Position getNewPos(Position oldPos, Direction dir);
  void attackEnemy( Direction dir );
  template<typename T> T enumRand();
  void moveEnemy(Enemy& enemy, Direction dir);

public:
  Floor();
  void spawn();
  void moveHero( Direction dir );
  void attack( Direction dir );
  void usePotion( Direction dir );
  void turn();

  friend std::ostream & operator<<( std::ostream & out, const Floor & f );
};

std::ostream & operator<<( std::ostream & out, const Floor & f );

#endif
