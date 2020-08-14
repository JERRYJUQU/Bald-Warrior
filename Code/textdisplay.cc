#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "subject.h"
#include "tile.h"
#include "hero.h"
#include "character.h"
#include "enemy.h"
#include "hero.h"
#include "item.h"

void TextDisplay::generateRows(char c){
  std::vector<char> row;
  row.emplace_back('|');
  for(int j=0; j < 77; j++){
    row.emplace_back(c);
  }
  row.emplace_back('|');
  theDisplay.emplace_back(row);
}

void TextDisplay::notify( Subject & whoNotified ) {
  ObjType ot = whoNotified.getType();
  switch(ot){
    case ObjType::character:{
      auto character = dynamic_cast<Character*> (&whoNotified);//Cast the subject to tile
      CharacterType ct = character->getCharacterType();
      switch(ct){
        case CharacterType::hero:{
          theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '@';
          std::string race;

          auto hero = dynamic_cast<Hero*> (&whoNotified);
          HeroType ht = hero->getHeroType();
          switch(ht){
            case HeroType::shade: race = "Shade"; break;
            case HeroType::drow: race = "Drow"; break;
            case HeroType::vampire: race = "Vampire"; break;
            case HeroType::troll: race = "Troll"; break;
            case HeroType::goblin: race = "Goblin"; break;
          }
          std::string hp = std::to_string(hero->getHP());
          std::string atk = std::to_string(hero->getAtk());
          std::string def = std::to_string(hero->getDef());
          std::string gold = std::to_string(hero->getGold());
          heroInfo = "Race: " + race + " Gold: " + gold + "                                                  " + "Floor " + std::to_string(hero->getFloor()) + "\n" + "HP: "+ hp + "\n" + "Atk: "+ atk + "\n" + "Def: "+ def;
          action = hero->getAction();
          break;
        }
        case CharacterType::enemy:{
          auto enemy = dynamic_cast<Enemy*> (&whoNotified);//Cast the subject to tile
          EnemyType et = enemy->getEnemyType();
          switch(et){
            case EnemyType::human: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'H'; break;
            case EnemyType::dwarf: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'W'; break;
            case EnemyType::elf: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'E'; break;
            case EnemyType::orcs: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'O'; break;
            case EnemyType::merchant: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'M'; break;
            case EnemyType::dragon: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'D'; break;
            case EnemyType::halfling: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'L'; break;
          }
        }
      }
      break;
    }
    case ObjType::item:{
      auto item = dynamic_cast<Item*> (&whoNotified);//Cast the subject to tile
      ItemType it = item->getItemType();
      switch(it){
        case ItemType::treasure: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'G'; break;
        case ItemType::potion: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = 'P'; break;
      }
      break;
    }
    case ObjType::tile:{
      auto tile = dynamic_cast<Tile*> (&whoNotified);//Cast the subject to tile
      TileType tt = tile->getTileType();
      switch(tt){
        case TileType::ground: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '.'; break;
        case TileType::hwall: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '-'; break;
        case TileType::vwall: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '|'; break;
        case TileType::doorway: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '+'; break;
        case TileType::hpassage: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '#'; break;
        case TileType::vpassage: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '#'; break;
        case TileType::empty: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = ' '; break;
        case TileType::stair: theDisplay[whoNotified.getPos().x][whoNotified.getPos().y] = '\\'; break;
      }
      break;
    }
  }
};

void TextDisplay::notifyDeath( Subject & whoNotified ) {}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
  //std::cout << ":eeee" << std::endl;
  for(int i=0; i<25; i++){
    for(int j=0; j<79; j++){
      out << td.theDisplay[i][j];
    }
    out << std::endl;
  }
  out << td.heroInfo << std::endl;
  out << "Action: " << td.action << std::endl;
  return out;
};
