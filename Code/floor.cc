#include "floor.h"
#include "tile.h"
#include <random>

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

bool Floor::checkCollision(Position pos, std::string type){
    int x = pos.x;
    int y = pos.y;
    if(type == "hero"){
        auto tile = dynamic_cast<Tile*> (tiles[y][x].get());//Cast the subject to tile
        TileType tt = tile->getTileType();
        bool t = (tt == TileType::ground || tt == TileType::hpassage || tt == TileType::vpassage || tt == TileType::doorway);
        bool e = !enemies[y][x];
        //bool p = !potions[y][x]; potions can be stepped on
        return t&&e;//&&p;
    }
}

bool Floor::guarded(std::shared_ptr<Treasure> treasue){
    return !treasue->pickUp();
}

Position Floor::getNewPos(Position oldPos, Direction dir){
    Position newPos(oldPos);
    // get new position
    switch(dir){
      case Direction::no: newPos.y -= 1;break;
      case Direction::so: newPos.y += 1;break;
      case Direction::ea: newPos.x += 1;break;
      case Direction::we: newPos.x -= 1;break;
      case Direction::ne: newPos.x += 1;newPos.y -= 1;break;
      case Direction::nw: newPos.x -= 1;newPos.y -= 1;break;
      case Direction::se: newPos.x += 1;newPos.y += 1;break;
      case Direction::sw: newPos.x -= 1;newPos.y += 1;break;
    }
    return newPos;
}

void Floor::moveHero( Direction dir ){
    Position oldPos = hero->getPos();
    Position newPos = getNewPos(oldPos, dir);
    //check weather new position is valid
    if(newPos.x < 0 || newPos.y > 0){
    }
    //check for any collision with other object
    if(!checkCollision(newPos, "hero")){
    }
    //check if hero entered stairs
    /*if(tiles[newPos.y][newPos.x]->getType() == TileType::stairs){

    }*/
    //check if hero is picking up a treasure
    if(treasures[newPos.y][newPos.x]){
        //check if treasure is guarded
        if (!guarded(treasures[newPos.y][newPos.x])) {
          hero->pickUpTreasure(*(treasures[newPos.y][newPos.x]));
            treasures[newPos.y][newPos.x] = nullptr;
            hero->move(dir);
            tiles[oldPos.y][oldPos.x]->notifyObservers();
            hero->notifyObservers();
            return;
        }
    }
    //hero moving onto an empty tile
    else{
        hero->move(dir);
        tiles[oldPos.y][oldPos.x]->notifyObservers();
        hero->notifyObservers();
        return;
    }
}

void Floor::attackEnemy( Direction dir ){
    Position oldPos = hero->getPos();
    Position newPos = getNewPos(oldPos, dir);
    //check if new position is valid
    if(newPos.x < 0 || newPos.y <0){
    }
    //check if there is enemy at that position
    if(!enemies[newPos.y][newPos.x]){
    }
    else{
        enemies[newPos.y][newPos.x]->defend(*hero);
    }
}
void Floor::usePotion( Direction dir ){
    Position oldPos = hero->getPos();
    Position newPos = getNewPos(oldPos, dir);
    //check if new position is valid
    if(newPos.x < 0 || newPos.y <0){
    }

};
void Floor::turn(){};
std::ostream & operator<<( std::ostream & out, const Floor & f ){
  out << *f.td;
  return out;
};
