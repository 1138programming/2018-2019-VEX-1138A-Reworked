#ifndef _SUBSYSTEMS_CLAW_H_
#define _SUBSYSTEMS_CLAW_H_

#include "./Subsystem.h"
#include "api.h"

class Claw : public libIterativeRobot::Subsystem {
  private:
    static Claw* instance;

    // Claw motors
    Motor* clawMotor;

    Claw();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Claw* getInstance();
};

#endif // _SUBSYSTEMS_CLAW_H_
