#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <memory>

class floor {
  std::unique_ptr<TextDisplay> td;
  std::vector<std::vector<Cell>> cells;

public:
  void generate();
  void spawn();
};

#endif
