#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include <vector>
#include "observer.h"

class Character;

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    size_t size;

 public:
    explicit TextDisplay( size_t n ) : size{n} {
      for(size_t i=0; i < n; i++){
        std::vector<char> row;
        for(size_t j=0; j < n; j++){
          row.emplace_back('_');
        }
        theDisplay.emplace_back(row);
      }
     };
    virtual void notify( Subject & whoNotified ) override;
    virtual void notify() override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif
