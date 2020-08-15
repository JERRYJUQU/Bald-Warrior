#include "floor.h"
#include <iostream>
#include <fstream>
int main(){
  std::ifstream ofile("openning.txt");
  std::string l;
  while (std::getline(ofile, l)) std::cout << l << std::endl;
  ofile.close();

  start:
  Floor f = Floor(1);

  char command;
  std::string line;
  bool spawned = false;

  while ( true ) {
    if(!spawned){
      std::cout << "\nEnter the race you wish to be:" << std::endl;
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
    std::cout << "Enter your command:" << std::endl;
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
      int state;
      if(line[0]=='u'){
        state = f.turn(Action::use, stodir(line.substr(2, 4)));
      }else if(line[0]=='a'){
        state = f.turn(Action::attack, stodir(line.substr(2, 4)));
      }else{
        state = f.turn(Action::move, stodir(line.substr(0, 2)));
      }
      switch(state){
        case 0: break;
        case 1: {
          std::ifstream file("death.txt");
          std::string l;
          while (std::getline(file, l)) std::cout << l << std::endl;
          file.close();
          std::cout << "Oops, you died! That's a bit sad, but we can try again!";
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
    std::cout << f;
  }
  end:
  std::ifstream efile("ending.txt");
  while (std::getline(efile, l)) std::cout << l << std::endl;
  efile.close();
};
