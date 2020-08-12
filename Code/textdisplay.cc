#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "subject.h"
#include "tile.h"
#include "character.h"

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
    case ObjType::character:
      auto character = dynamic_cast<Character*> (&whoNotified);//Cast the subject to tile
      CharacterType ct = character->getCharacterType();

      break;
    case ObjType::item: break;
    case ObjType::tile:
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
      }
      break;
  }
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
  for(int i=0; i<25; i++){
    for(int j=0; j<79; j++){
      out << td.theDisplay[i][j];
    }
    out << std::endl;
  }
  return out;
};
