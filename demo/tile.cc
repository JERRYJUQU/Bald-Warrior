#include "tile.h"
Tile::Tile( TileType type, Position pos ) : Subject{pos, ObjType::tile}, type{type} {};
TileType Tile::getTileType(){ return type; };
