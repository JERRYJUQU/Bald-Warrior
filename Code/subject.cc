#include "subject.h"
#include "observer.h"
Subject::Subject( Position pos, ObjType type ) : pos{pos}, type{type} {};
Subject::~Subject(){};

void Subject::attach(std::shared_ptr<Observer> o) { observers.emplace_back(o); }

Position Subject::getPos(){ return pos; };
ObjType Subject::getType(){ return type; };

void Subject::notifyObservers() {
    for (auto &ob : observers) ob->notify( *this );
}
