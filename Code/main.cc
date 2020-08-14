#include "floor.h"
#include <iostream>
int main(){
  Floor f = Floor();

  char command, race;
  std::string line;
  int fl;
  bool spawned;

  while ( true ) {
    if(!spawned){
      std::cout << "Enter the race:" << std::endl;
      std::cin >> race;

      switch( race ) {
        case 's': f.spawn(HeroType::shade); break;
        case 'd': f.spawn(HeroType::drow); break;
        case 'v': f.spawn(HeroType::vampire); break;
        case 'g': f.spawn(HeroType::goblin); break;
        case 't': f.spawn(HeroType::troll); break;
        default: f.spawn(HeroType::shade); break;
      }
    }

    std::cout << f;
    std::cin >> command;

    if ( std::cin.fail() || command == 'q' ) break;
    /*switch( command ) {
      case 'no':
      case 'no':

    }*/
    std::cout << f;
  }

};
