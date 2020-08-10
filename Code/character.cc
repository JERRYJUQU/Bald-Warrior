#include character.h
#include position.h
#include observer.h

Character::Character(Position pos):pos{pos}, hp{0}, atk{0},def{0} {}

Position Character::getPos() return pos;
int Character::getHP() return hp;
int Character::getAtk() return atk;
int Character::getDef() return def;
void Character::incHP(int hp){
        int tmp = this->hp + hp;
        if(tmp < 0){
                this->hp = 0;
        }else if(tmp > maxHP){
                this->hp = maxHP;
        }else{
                this->hp = tmp;
        }        
        return;
}
void Character::setHP(int hp){
        if(hp < 0){
                this->hp = 0;
        }else if(hp > maxHP){
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
void Character::setDef(){
        this->def  = def;
        return;
}
void Character::attach(shared_ptr<Observer> observer){
        observers.push_back(observer);
        return;
}

