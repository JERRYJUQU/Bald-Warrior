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

enum class Direction { no,so,ea,we,ne,nw,se,sw };

class Observer;
class Stair;

class Floor {
  std::string name;
  std::shared_ptr<Hero> hero;
  std::shared_ptr<Stair> stair;
  std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
  std::vector<std::vector<std::shared_ptr<Enemy>>> enemies;
  std::vector<std::shared_ptr<Potion>> potions;
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
