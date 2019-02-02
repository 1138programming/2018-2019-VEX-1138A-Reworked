#ifndef _SUBSYSTEMS_FLIPPER_H_
#define _SUBSYSTEMS_FLIPPER_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Flipper : public libIterativeRobot::Subsystem {
  private:
    Motor* flipperMotor;
  public:
    void initDefaultCommand();
    void runFlipper(int velocity);
    Flipper();
};

#endif // _SUBSYSTEMS_FLIPPER_H_
