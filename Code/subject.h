#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <vector>
#include <memory>
#include "position.h"
enum class ObjType { character, item, tile };

class Observer;

class Subject {
    ObjType type;
protected:
    Position pos;
    std::vector<std::shared_ptr<Observer>> observers;

  public:
    Subject( Position pos, ObjType type );
    virtual ~Subject();
    Position getPos();
    ObjType getType();
    void attach(std::shared_ptr<Observer> o);
    void notifyObservers();
};

#endif
