#include "subject.h"
#include "observer.h"
Subject::Subject( Position pos, ObjType type ) : type{type}, pos{pos} {};
Subject::~Subject(){};

void Subject::attach(std::shared_ptr<Observer> o) { observers.emplace_back(o); }

Position Subject::getPos(){ return pos; };
void Subject::setPos(Position p){ pos = p; };
ObjType Subject::getType(){ return type; };

void Subject::notifyObservers() {
    for (auto &ob : observers) ob->notify( *this );
}
