#ifndef _OBSERVER_H_
#define _OBSERVER_H_

// DO NOT MODIFY THIS FILE!

class Subject;

class Observer {
  public:
    // Pass the Subject that called the notify method.
    virtual void notify( Subject & whoNotified ) = 0;
    virtual void notifyDeath( Subject & whoNotified ) = 0;
    virtual ~Observer() = default;
};

#endif
