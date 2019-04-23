#ifndef _SUBSYSTEMS_FLIPPER_H_
#define _SUBSYSTEMS_FLIPPER_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Flipper : public libIterativeRobot::Subsystem {
  private:
    Motor* flipperMotor;
    PIDController* flipperControl;
  public:
    void initDefaultCommand();
    void runFlipper(int velocity);
    void setSetpoint(int setpoint);
    void setSetpointRelative(int setpoint);
    bool atTarget();
    int getEncoderValue();
    void enable();
    void disable();
    int bottomLimit;
    Flipper();
};

#endif // _SUBSYSTEMS_FLIPPER_H_
