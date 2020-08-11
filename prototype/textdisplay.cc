#include <iostream>
#include <vector>
#include "textdisplay.h"

void TextDisplay::notify( Subject & whoNotified ) {
  Info info = whoNotified.getInfo();
  if(info.state == State::Alive){
    theDisplay[info.row][info.col] = 'X';
  }else{
    theDisplay[info.row][info.col] = '_';
  }
};
void TextDisplay::notify() {};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
  for(size_t i=0; i<td.size; i++){
    for(size_t j=0; j<td.size; j++){
      out << td.theDisplay[j][i];
    }
    out << std::endl;
  }
  return out;
};
