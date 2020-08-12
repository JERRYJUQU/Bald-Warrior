#include "hero.h"
#include "floor.h"

Hero::Hero(Position pos):Character{pos}, gold{0}, maxHP{0} {}

int Hero::getGold() { return gold; };
int Hero::getMaxHP() { return maxHP; };
void Hero::incGold(int gold){
        this->gold += gold;
}
void Hero::pickUpTreasure(Treasure & treasure){
        treasure.effect(*this);
}
/*void move(Direction direction){
  Position newPos = Character::getPos();
  // get new position
  switch(direction){
    case Direction::no: newPos.y -= 1;break;
    case Direction::so: newPos.y += 1;break;
    case Direction::ea: newPos.x += 1;break;
    case Direction::we: newPos.x -= 1;break;
    case Direction::ne: newPos.x += 1;newPos.y -= 1;break;
    case Direction::nw: newPos.x -= 1;newPos.y -= 1;break;
    case Direction::se: newPos.x += 1;newPos.y += 1;break;
    case Direction::sw: newPos.x -= 1;newPos.y += 1;break;
  }
  pos = newPos;
}*/

void Hero::notifyDeath(){
        /*for(auto p : observers){
                p.notifyDeath(*this);
        }*/
}
