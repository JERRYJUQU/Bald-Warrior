#include "floor.h"
#include <iostream>
#include<fstream>
int main(){
  start:
  Floor f = Floor(1);

  char command;
  std::string line;
  bool spawned = false;

  while ( true ) {
    if(!spawned){
      std::cout << "Enter the race:" << std::endl;
      std::cin >> command;
      if (std::cin.fail()) break;
      switch( command ) {
        case 'q': exit(0);
        case 's': f.spawn(HeroType::shade); break;
        case 'd': f.spawn(HeroType::drow); break;
        case 'v': f.spawn(HeroType::vampire); break;
        case 'g': f.spawn(HeroType::goblin); break;
        case 't': f.spawn(HeroType::troll); break;
        default: f.spawn(HeroType::shade); break;
      }
      spawned = true;
      std::cout << f;
      cin.ignore();
    }
    std::getline(std::cin, line);
    if (std::cin.fail()) break;
    if(line.length() == 1){
      if(line[0] == 'f'){
        f.setPause();
      }else if(line[0] == 'r'){
        goto start;
      }else if(line[0] == 'q'){
        exit(0);
        break;
      }
    }else{
      if(line[0]=='u'){
        f.turn(Action::use, stodir(line.substr(2, 4)));
      }else if(line[0]=='a'){
        f.turn(Action::attack, stodir(line.substr(2, 4)));
      }else{
        int state = f.turn(Action::move, stodir(line.substr(0, 2)));
        switch(state){
          case 0: break;
          case 1: {
            std::cout << "Oops! You have died!" << std::endl;
            goto start;
          }
          case 2:{
            std::shared_ptr<Hero> hero = f.getHero();
            if(hero->getFloor() < 5){
              hero->incFloor();
              f = Floor(hero->getFloor());
              f.enter(hero);
            }else{
              goto end;
            }
            break;
          }
        }
      }
    }
    std::cout << f;
  }
  end:
  std::cout << "Congradulations! You have completed CC3K." << std::endl;
};
