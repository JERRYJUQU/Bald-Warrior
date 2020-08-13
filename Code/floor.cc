#include "floor.h"
#include "stair.h"
#include <stdlib.h> //dont delete
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
      row.emplace_back(tile);
    }
    tiles.emplace_back(row);
    ++r;
  }


  //Initialize maps
  for(int r = 0; r < 25; r++){
    std::vector<std::shared_ptr<Enemy>> row;
    for(int c = 0; c < 79; c++){
        row.emplace_back();
    }
    enemies.emplace_back(row);
  }

  for(int r = 0; r < 25; r++){
    std::vector<std::shared_ptr<Potion>> row;
    for(int c = 0; c < 79; c++){
        row.emplace_back();
    }
    potions.emplace_back(row);
  }

  for(int r = 0; r < 25; r++){
    std::vector<std::shared_ptr<Treasure>> row;
    for(int c = 0; c < 79; c++){
        row.emplace_back();
    }
    treasures.emplace_back(row);
  }

  spawn();
  //struct Position pos = { 10, 10 };
  //Hero hero = Hero(pos, HeroType::shade);
}
void Floor::spawn(){

  std::vector<std::shared_ptr<Tile>> valid;
  for(auto &row : tiles){
    for(auto &col : row){
      TileType tt = col->getTileType();
      if(tt == TileType::ground){
        valid.emplace_back(col);
      }
    }
  }

  //Generate stair
  int i = (rand()%valid.size());
  stair = make_shared<Stair>( valid[i]->getPos() );
  stair->attach(td);
  stair->notifyObservers();
  valid.erase(valid.begin()+i);

  //Generate Hero
  i = (rand()%valid.size());
  hero = make_shared<Shade>( valid[i]->getPos() );
  hero->attach(td);
  hero->notifyObservers();
  valid.erase(valid.begin()+i);

  //Generate enemies
  std::shared_ptr<Enemy> enemy;
  for(int j = 0; j < 20; j++){
    i = (rand()%valid.size());//Generate a random element in the valid tiles

    struct Position validPos = valid[i]->getPos();
    int t = rand()%18;//Get a random number between 0 to 18
    if(t < 4){// 2/9 chance of being human
      enemy = make_shared<Human>( validPos );
    }else if(t < 7){// 3/18 chance of being dwarf
      enemy = make_shared<Dwarf>( validPos );
    }else if(t < 12){// 5/18 chance of being halfing
      enemy = make_shared<Halfling>( validPos );
    }else if(t < 14){// 1/9 chance of being elf
      enemy = make_shared<Elf>( validPos );
    }else if(t < 16){// 1/9 chance of being orc
      enemy = make_shared<Orcs>( validPos );
    }else{// 1/9 chance of being merchant
      enemy = make_shared<Merchant>( validPos );
    }
    enemy->attach(td);
    enemy->notifyObservers();
    enemies[validPos.x][validPos.y] = enemy;
    valid.erase(valid.begin()+i);
  }

  for(int j = 0; j < 10; j++){
    i = (rand()%valid.size());
    struct Position validPos = valid[i]->getPos();
    int t = rand()%6;//Get a random number between 0 to 18
    std::shared_ptr<Potion> potion;
    switch(t){
        case 0: potion = make_shared<RestoreHealth>( validPos ); break;
        case 1: potion = make_shared<BoostAtk>( validPos ); break;
        case 2: potion = make_shared<BoostDef>( validPos ); break;
        case 3: potion = make_shared<PoisonHealth>( validPos ); break;
        case 4: potion = make_shared<WoundAtk>( validPos ); break;
        case 5: potion = make_shared<WoundDef>( validPos ); break;
    }

    potion->attach(td);
    potion->notifyObservers();
    potions[validPos.x][validPos.y] = enemy;
    valid.erase(valid.begin()+i);
  }

  //Generate treasures
  for(int j = 0; j < 10; j++){
    i = (rand()%valid.size());

    struct Position validPos = valid[i]->getPos();
    int t = rand()%8;//Get a random number between 0 to 8
    std::shared_ptr<Treasure> treasure;

    if(t < 5){// 5/8 chance of being normal
        treasure = make_shared<NormalHoard>( validPos );
    }else if(t < 6){// 1/8 chance of being dragon hoard
        treasure = make_shared<DragonHoard>( validPos );
    }else{// 1/4 chance of being small
        treasure = make_shared<SmallHoard>( validPos );
    }

    treasure->attach(td);
    treasure->notifyObservers();
    treasures[validPos.x][validPos.y] = enemy;
    valid.erase(valid.begin()+i);
  }
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
    if(newPos.x < 0 || newPos.y < 0 || newPos.x > 78 || newPos.y > 24){
    }
    //check if there is enemy at that position
    if(!enemies[newPos.y][newPos.x]){
        //throw exception
    }
    else{
        enemies[newPos.y][newPos.x]->defend(*hero);
    }
}
void Floor::usePotion( Direction dir ){
    Position oldPos = hero->getPos();
    Position newPos = getNewPos(oldPos, dir);
    //check if new position is valid
    if(newPos.x < 0 || newPos.y < 0 || newPos.x > 78 || newPos.y > 24){
        //throw exception
    }
    if (!potions[newPos.y][newPos.x]) {
        //throw exception
    }
    else {
        hero->usePotion(*potions[newPos.y][newPos.x]);
    }

};

template<typename T>
T Floor::enumRand() {
    const int enumSize = (int) T::COUNT;
    return static_cast<T> (rand() % enumSize);
}

void Floor::turn() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            if (!enemies[i][j]) {
                if (enemies[i][j]->getHP() <= 0) {
                    enemies[i][j]->notifyDeath();
                    switch (enemies[i][j]->getEnemyType()) {
                    case EnemyType::human:
                        hero->incGold(4); // increase gold instead of dropping hoard, may need to change
                        break;
                    case EnemyType::dragon:
                        enemies[i][j]->notifyDeath();
                    case EnemyType::merchant:
                        hero->incGold(4); //increase gold instead of dropping hoard, may need to change
                    }
                    enemies[i][j] = nullptr;
                }
                else if (abs(hero->getPos().x - enemies[i][j]->getPos().x) < 2 &&
                    abs(hero->getPos().y - enemies[i][j]->getPos().y) < 2) {
                     enemies[i][j]->attack(*hero);
                }
                else {
                    enemies[i][j]->move(enumRand<Direction>());
                }
            }
        }
     }
}

std::ostream & operator<<( std::ostream & out, const Floor & f ){
  out << *f.td;
  return out;
};
