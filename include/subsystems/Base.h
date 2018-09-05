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

    bool isReversed;

    Base();
  public:
    void initDefaultCommand();
    void move(int left, int right);
    void setBaseReversed(bool isReversed);
    bool getReversed();
    static Base* getInstance();
};

#endif
