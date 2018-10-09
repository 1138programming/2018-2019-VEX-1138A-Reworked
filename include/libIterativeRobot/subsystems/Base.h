#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"

class Base : public libIterativeRobot::Subsystem {
  private:
    static Base* instance;

    // Base motors
    Motor* leftMotor;
    Motor* rightMotor;

    Base();
  public:
    void initDefaultCommand();
    void move(int left, int right);
    static Base* getInstance();
};

#endif // _SUBSYSTEMS_BASE_H_
