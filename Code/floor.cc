#include "floor.h"
#include "tile.h"

Floor::Floor() : name{""} {
  td = std::make_shared<TextDisplay>();
  std::istringstream ss(map);
  std::string s;
  int r = 0;
  while(getline(ss, s)){
    std::vector<std::shared_ptr<Tile>> row;
    for (int c = 0; c < 79; c++){
      TileType type;
      if(s[c] == '.'){
        type = TileType::ground;
      }else if(s[c] == '-'){
        type = TileType::hwall;
      }else if(s[c] == '|'){
        type = TileType::vwall;
      }else if(s[c] == '+'){
        type = TileType::doorway;
      }else if(s[c] == '#'){
        type = TileType::hpassage;
      }else{
        type = TileType::empty;
      }
      struct Position pos = { r, c };
      std::shared_ptr<Tile> tile = std::make_shared<Tile>(type, pos);
      tile->attach(td);
      tile->notifyObservers();
      row.emplace_back();
    }
    tiles.emplace_back(row);
    ++r;
  }

}
void Floor::spawn(){

};
void Floor::moveHero( Direction dir ){};
void Floor::attack( Direction dir ){};
void Floor::usePotion( Direction dir ){};
void Floor::turn(){};
std::ostream & operator<<( std::ostream & out, const Floor & f ){
  out << *f.td;
  return out;
};
