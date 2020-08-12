#ifndef STAIR_H
#define STAIR_H
#include <iostream>
#include "position.h"
#include "tile.h"

class Observer;

class Stair : public Tile {

  public:
      Stair(Position pos) : Tile{TileType::stair, pos} {};
};

#endif
