// 1 motor

#ifndef TURNTABLE_H
#define TURNTABLE_H

#include "main.h"

class Turntable : public Subsystem {
  private:
    static Turntable* instance;
    Motor* turntableMotor;
    Turntable();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Turntable* getInstance();
};

#endif
