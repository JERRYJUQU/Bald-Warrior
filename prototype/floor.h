#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <vector>
#include <memory>
#include "character.h"
#include "chamber.h"

class TextDisplay;
class Observer;

class floor {
  std::vector<std::shared_ptr<Character>> characters;
  std::vector<Chamber>


public:
  void generate();
  void spawn();

};


#endif
