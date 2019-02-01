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
    void runFlipperForward(int velocity);
    void runFlipperBackward(int velocity);
    void runFlipperDriver(int velocity);
    Flipper();
};

#endif // _SUBSYSTEMS_FLIPPER_H_
