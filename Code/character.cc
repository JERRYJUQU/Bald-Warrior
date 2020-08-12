#include "character.h"
#include "position.h"
#include "observer.h"
#include "subject.h"
#include "floor.h"

Character::Character(Position pos, CharacterType type): Subject{pos, ObjType::character}, type{type}, hp{0}, atk{0},def{0} {}

Position Character::getPos() { return pos; }
int Character::getHP() { return hp; }
int Character::getAtk() { return atk; }
int Character::getDef() { return def; }
void Character::incHP(int hp){
        int tmp = this->hp + hp;
        if(tmp < 0){
                this->hp = 0;
        }else if(tmp > getMaxHP()){
                this->hp = getMaxHP();
        }else{
                this->hp = tmp;
        }
        return;
}
void Character::setHP(int hp){
        if(hp < 0){
                this->hp = 0;
        }else if(hp > getMaxHP()){
                this->hp = getMaxHP();
        }else{
                this->hp = hp;
        }
        return;
}
void Character::setAtk(int atk){
        this->atk = atk;
        return;
}
void Character::setDef(int def){
        this->def  = def;
        return;
}
void Character::move(Direction dir){
  // get new position
  switch(dir){
    case Direction::no: pos.y -= 1;break;
    case Direction::so: pos.y += 1;break;
    case Direction::ea: pos.x += 1;break;
    case Direction::we: pos.x -= 1;break;
    case Direction::ne: pos.x += 1;pos.y -= 1;break;
    case Direction::nw: pos.x -= 1;pos.y -= 1;break;
    case Direction::se: pos.x += 1;pos.y += 1;break;
    case Direction::sw: pos.x -= 1;pos.y += 1;break;
  }
}
