#include "enemy.h"
#include "character.h"

Enemy::Enemy(Position pos, EnemyType type): Character{pos, CharacterType::enemy}, neutral{false}, type{type}{}
EnemyType Enemy::getEnemyType(){ return type; };

bool Enemy::getNeutral(){ return neutral; };
void Enemy::setNeutral(bool n){ neutral = n;};
void Enemy::notifyDeath(){
        /*for(auto n : observers){
                n->notifyDeath(*this);
        }*/
}
/*
void Enemy::move(Direction direction){
        if(direction == "no"){
                pos.y -= 1;
        }else if(direction == "so"){
                pos.y += 1;
        }else if(direction == "ea"){
                pos.x += 1;
        }else if(direction == "we"){
                pos.x -= 1;
        }else if(direction == "ne"){
                pos.x += 1;
                pos.y -= 1;
        }else if(direction == "nw"){
                pos.x -= 1;
                pos.y -= 1;
        }else if(direction == "se"){
                pos.x += 1;
                pos.y += 1;
        }else if(direction == "sw"){
                pos.x -= 1;
                pos.y += 1;
        }
}*/
