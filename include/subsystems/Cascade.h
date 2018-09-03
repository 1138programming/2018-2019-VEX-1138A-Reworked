// 2 motors, y-cabled

#ifndef Cascade_H
#define Cascade_H

#include "main.h"

class Cascade : public Subsystem {
  private:
    static Cascade* instance;
    Motor* cascadeMotorOne;
    Motor* cascadeMotorTwo;
    Cascade();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Cascade* getInstance();
};

#endif
