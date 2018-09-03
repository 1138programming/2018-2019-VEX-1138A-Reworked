// 6 motors

#ifndef BASE_H
#define BASE_H

#include "main.h"

class Base : public Subsystem {
  private:
    static Base* instance;

    // Left base motors
    Motor* leftFrontBaseMotor;
    Motor* leftRearBaseMotor;

    // Right base motors
    Motor* rightFrontBaseMotor;
    Motor* rightRearBaseMotor;

    Base();
  public:
    void initDefaultCommand();
    void move(int left, int right);
    static Base* getInstance();
};

#endif
