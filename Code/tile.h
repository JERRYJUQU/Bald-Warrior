#ifndef TILE_H
#define TILE_H
#include <vector>
#include "position.h"
#include "subject.h"
enum class TileType { ground, hwall, vwall, doorway, hpassage, vpassage, empty };

class Tile : public Subject{
  TileType type;
public:
  Tile( TileType type, Position pos );
  TileType getTileType();
};

#endif
