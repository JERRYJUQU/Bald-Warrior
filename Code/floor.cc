#include "floor.h"
#include "stair.h"

#include <stdlib.h> //dont delete
#include <random>
#include <ctime>

Floor::Floor(int n) : n{n}, pause{false}, enteredStair{false} {
  // initialize textdisplay
  td = std::make_shared<TextDisplay>();
  // initialize tile map
  // attach text display observer
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
  //struct Position pos = { 10, 10 };
  //Hero hero = Hero(pos, HeroType::shade);
}

void Floor::refreshDisplay(){
  for(int i = 0; i < 25; i++){
    for(int j = 0; j < 79; j++){
      if(tiles[i][j]) tiles[i][j]->notifyObservers();
      if(potions[i][j]) potions[i][j]->notifyObservers();
      if(treasures[i][j]) treasures[i][j]->notifyObservers();
      if(enemies[i][j]) enemies[i][j]->notifyObservers();
    }
  }
  stair->notifyObservers();
  hero->notifyObservers();
}

void Floor::spawn(HeroType ht){
  srand(time(0));
  // initialize vector that contains all ground tiles
  std::vector<std::shared_ptr<Tile>> valid;
  for(auto &row : tiles){
    for(auto &col : row){
      TileType tt = col->getTileType();
      if(tt == TileType::ground){
        valid.emplace_back(col);
      }
    }
  }

  //Generate chambers
  std::vector<std::vector<std::shared_ptr<Tile>>> chambers(5);
  std::shared_ptr<TextDisplay> tp = std::make_shared<TextDisplay>();;
  for(auto e : valid){
    struct Position pos = e->getPos();
    if((3 <= pos.x && pos.x <= 6) && (3 <= pos.y && pos.y <= 28)){
      chambers[0].emplace_back(e);
    }else if( (9 <= pos.x && pos.x <= 24) && (3 <= pos.y && pos.y <= 28) ){
      chambers[1].emplace_back(e);
    }else if( (9 <= pos.x && pos.x <= 13) && (30 <= pos.y && pos.y <= 50) ){
      chambers[2].emplace_back(e);
    }else if(( 3 <= pos.x && pos.x <= 6 && 30 <= pos.y ) || (6 <= pos.x && pos.x <= 13 && 60 <= pos.y)){
      chambers[3].emplace_back(e);
    }else{
      e->attach(tp);
      chambers[4].emplace_back(e);
    }
  }
  // delete valid
  valid.clear();

  //Generate stair
  int c = (rand()%5);
  int i = (rand()%(chambers[c].size()));
  stair = make_shared<Stair>( chambers[c][i]->getPos() );
  stair->attach(td);
  chambers[c].erase(chambers[c].begin()+i);

  //Generate Hero
  c = (rand()%5);
  i = (rand()%chambers[c].size());
  switch(ht){
    case HeroType::shade: hero = make_shared<Shade>( chambers[c][i]->getPos() ); break;
    case HeroType::drow: hero = make_shared<Drow>( chambers[c][i]->getPos() ); break;
    case HeroType::vampire: hero = make_shared<Vampire>( chambers[c][i]->getPos() ); break;
    case HeroType::troll: hero = make_shared<Troll>( chambers[c][i]->getPos() ); break;
    case HeroType::goblin: hero = make_shared<Goblin>( chambers[c][i]->getPos() ); break;
  }
  hero->attach(td);
  chambers[c].erase(chambers[c].begin()+i);

  //Generate enemies
  for(int j = 0; j < 20; j++){
    c = (rand()%5);
    i = (rand()%chambers[c].size());//Generate a random element in the valid tiles

    std::shared_ptr<Enemy> enemy;
    struct Position validPos = chambers[c][i]->getPos();
    int t = rand()%18;//Get a random number between 0 to 18
    if(t < 4){// 2/9 chance of being human
      enemy = std::make_shared<Human>( validPos );
    }else if(t < 7){// 3/18 chance of being dwarf
      enemy = std::make_shared<Dwarf>( validPos );
    }else if(t < 12){// 5/18 chance of being halfing
      enemy = std::make_shared<Halfling>( validPos );
    }else if(t < 14){// 1/9 chance of being elf
      enemy = std::make_shared<Elf>( validPos );
    }else if(t < 16){// 1/9 chance of being orc
      enemy = std::make_shared<Orcs>( validPos );
    }else{// 1/9 chance of being merchant
      enemy = std::make_shared<Merchant>( validPos );
    }
    enemy->attach(td);
    enemies[validPos.x][validPos.y] = enemy;
    chambers[c].erase(chambers[c].begin()+i);
  }
  
  // generate potions
  for(int j = 0; j < 10; j++){
    c = (rand()%5);
    i = (rand()%chambers[c].size());
    struct Position validPos = chambers[c][i]->getPos();
    int t = (rand()%6);//Get a random number between 0 to 6
    std::shared_ptr<Potion> potion;

    switch(t){
        case 0: potion = std::make_shared<RestoreHealth>( validPos );  break;
        case 1: potion = std::make_shared<BoostAtk>( validPos ); break;
        case 2: potion = std::make_shared<BoostDef>( validPos ); break;
        case 3: potion = std::make_shared<PoisonHealth>( validPos ); break;
        case 4: potion = std::make_shared<WoundAtk>( validPos ); break;
        case 5: potion = std::make_shared<WoundDef>( validPos ); break;
    }

    potion->attach(td);
    //std::cout << *td << std::endl;
    potions[validPos.x][validPos.y] = potion;
    chambers[c].erase(chambers[c].begin()+i);
  }

  //Generate treasures
  for(int j = 0; j < 10; j++){
    c = (rand()%5);
    i = (rand()%chambers[c].size());

    struct Position validPos = chambers[c][i]->getPos();
    int t = rand()%8;//Get a random number between 0 to 8
    std::shared_ptr<Treasure> treasure;

    if(t < 5){// 5/8 chance of being normal
        treasure = std::make_shared<NormalHoard>( validPos );
    }else if(t < 6){// 1/8 chance of being dragon hoard
        treasure = std::make_shared<DragonHoard>( validPos );

    }else{// 1/4 chance of being small
        treasure = std::make_shared<SmallHoard>( validPos );
    }

    treasure->attach(td);
    treasures[validPos.x][validPos.y] = treasure;
    chambers[c].erase(chambers[c].begin()+i);
  }
  refreshDisplay();
};

void Floor::enter(std::shared_ptr<Hero> h){
  spawn(h->getHeroType());
  h->setPos(hero->getPos());
  // keep old stats from previous level
  hero = h;
  hero->attach(td);
  refreshDisplay();
}

void Floor::setPause(){ pause = !pause; };
bool Floor::haveEnteredStair(){ return enteredStair; };
std::shared_ptr<Hero> Floor::getHero(){ return hero; };

std::vector<Position> Floor::getValidPos(Position pos){
  std::vector<Position> result;
  for(int dx = -1; dx < 2; dx++){
    for(int dy = -1; dy < 2; dy++){
      int nx = min(max(pos.x+dx, 0), 25);
      int ny = min(max(pos.y+dy, 0), 78);
      if(!enemies[nx][ny] && !(nx == hero->getPos().x && ny == hero->getPos().y) && !(nx == stair->getPos().x && ny == stair->getPos().y)){
        if(tiles[nx][ny]->getTileType() == TileType::ground){
          struct Position np = { nx, ny };
          result.emplace_back(np);
        }
      }
    }
  }
  return result;
};



bool Floor::guarded(std::shared_ptr<Treasure> treasue){
    return !treasue->pickUp();
}

Position Floor::getNewPos(Position oldPos, Direction dir){
    Position newPos(oldPos);
    // get new position
    switch(dir){
      case Direction::no: newPos.x -= 1;break;
      case Direction::so: newPos.x += 1;break;
      case Direction::ea: newPos.y += 1;break;
      case Direction::we: newPos.y -= 1;break;
      case Direction::ne: newPos.y += 1;newPos.x -= 1;break;
      case Direction::nw: newPos.y -= 1;newPos.x -= 1;break;
      case Direction::se: newPos.y += 1;newPos.x += 1;break;
      case Direction::sw: newPos.y -= 1;newPos.x += 1;break;
      case Direction::COUNT: break;
    }
    return newPos;
}

void Floor::moveHero( Direction dir ){

    Position oldPos = hero->getPos();
    Position newPos = getNewPos(oldPos, dir);
    //check weather new position is valid
    if(newPos.x < 0 || newPos.x > 24 || newPos.y < 0 || newPos.y > 78){
      return;
    }
    std::shared_ptr<Tile> t = tiles[newPos.x][newPos.y];
    if(t->getTileType() == TileType::hwall || t->getTileType() == TileType::vwall || t->getTileType() == TileType::empty){
      return;
    }
    //check for any collision with other object
    if(enemies[newPos.x][newPos.y]){
      return;
    }
    //check if hero entered stairs
    if(stair->getPos().x == newPos.x && stair->getPos().y == newPos.y){
      enteredStair = true;
      return;
    }
    //check if hero is picking up a treasure
    if(treasures[newPos.x][newPos.y]){
        //check if treasure is guarded
        if (!guarded(treasures[newPos.x][newPos.y])) {
          hero->pickUpTreasure(*(treasures[newPos.x][newPos.y]));
            treasures[newPos.x][newPos.y] = nullptr;
        }
    }

    hero->setPos(newPos);
    hero->setAction("PC moves " + dirtos(dir));
    return;
}

void Floor::attackEnemy( Direction dir ){
    Position heroPos = hero->getPos();
    //check if new position is valid
    if(heroPos.x < 0 || heroPos.y < 0 || heroPos.x > 24 || heroPos.y > 78){
      return;
    }
    //check if there is enemy at that position
    if(!enemies[heroPos.y][heroPos.x]){
      return;
    }else{
        enemies[heroPos.y][heroPos.x]->defend(*hero);
    }
}
void Floor::usePotion( Direction dir ){
    Position heroPos = hero->getPos();
    //check if new position is valid
    if(heroPos.x < 0 || heroPos.y < 0 || heroPos.x > 24 || heroPos.y > 78){
      return;
    }
    if (!potions[heroPos.y][heroPos.x]) {
      return;
    }else{
        hero->usePotion(*potions[heroPos.y][heroPos.x]);
        potions[heroPos.y][heroPos.x] = nullptr;
    }
};

//Randomly select an element fron enum class
template<typename T>
T Floor::enumRand() {
    srand(time(0));
    const int enumSize = (int) T::COUNT;
    return static_cast<T> (rand() % enumSize);
}

void Floor::turn(Action action, Direction dir) {
  switch(action){
    case Action::use: usePotion( dir ); break;
    case Action::attack: attackEnemy( dir ); break;
    case Action::move: moveHero( dir ); break;
  }
  
  std::vector<std::shared<Enemy>> moved;
  for (int i = 0; i < 25; i++) {
      for (int j = 0; j < 79; j++) {
          
          if (enemies[i][j]) {
              auto it = std::find( moved.begin(), moved.end(), enemies[i][j]);
              if (it != moved.end()){//enemies had been moved
                  continue;
              }
              if (enemies[i][j]->getHP() <= 0) {
                  enemies[i][j]->notifyDeath();
                  switch (enemies[i][j]->getEnemyType()) {
                  // need more implement
                  case EnemyType::dwarf:
                      break;
                  case EnemyType::human:
                      hero->incGold(4); // increase gold instead of dropping hoard, may need to change
                      break;
                  case EnemyType::dragon:
                      enemies[i][j]->notifyDeath();
                      break;
                  case EnemyType::merchant:
                      hero->incGold(4); //increase gold instead of dropping hoard, may need to change
                      break;
                  default: break;
                  }
                  // clear pointer in map
                  enemies[i][j] = nullptr;
              }else if (abs(hero->getPos().x - enemies[i][j]->getPos().x) < 2 &&
                  abs(hero->getPos().y - enemies[i][j]->getPos().y) < 2 &&
                  !enemies[i][j]->getNeutral()) {
                   hero->defend(*enemies[i][j]);
              }else {
                if(!pause){
                  std::vector<Position> validPos = getValidPos(enemies[i][j]->getPos());
                  srand(time(0));
                  int p = rand()%validPos.size();
                  enemies[i][j]->setPos(validPos[p]);
                  swap(enemies[i][j], enemies[validPos[p].x][validPos[p].y]);//swap the locations
                }
              }
            moved.emplace_back(enemies[i][j]);
          }
      }
  }
  refreshDisplay();
}

std::ostream & operator<<( std::ostream & out, const Floor & f ){
  out << *f.td;
  return out;
};
