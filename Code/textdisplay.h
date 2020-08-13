#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    void generateRows(char c);//Implicit helper to generate rows

 public:
    explicit TextDisplay() {
      generateRows('-');
      for(int i=0; i < 23; i++){
        generateRows(' ');
      }
      generateRows('-');
     };
    virtual void notify( Subject & whoNotified ) override;
    virtual void notifyDeath( Subject & whoNotified ) override;

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

#endif
