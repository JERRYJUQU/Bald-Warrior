#include "character.h"

Character::Character(Position pos, CharacterType type): Subject{pos, ObjType::character}, type{type}, hp{0}, atk{0},def{0}, maxHP{0} {}

Position Character::getPos() { return pos; }
int Character::getHP() { return hp; }
int Character::getAtk() { return atk; }
int Character::getDef() { return def; }
int Character::getMaxHP() { return maxHP; }
void Character::incHP(int hp){
        int tmp = this->hp + hp;
        if(tmp < 0){
                this->hp = 0;
        }else if(tmp > getMaxHP()){
                this->hp = maxHP;
        }else{
                this->hp = tmp;
        }

        return;
}
CharacterType Character::getCharacterType(){return type; };
void Character::setHP(int hp){
        if(hp < 0){
                this->hp = 0;
        }else if(hp > getMaxHP()){
                this->hp = maxHP;
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
