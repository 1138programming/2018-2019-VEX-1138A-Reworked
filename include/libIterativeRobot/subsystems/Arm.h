#ifndef _SUBSYSTEMS_ARM_H_
#define _SUBSYSTEMS_ARM_H_

#include "./Subsystem.h"
#include "api.h"

class Arm : public libIterativeRobot::Subsystem {
  private:
    static Arm* instance;

    // Arm motors
    Motor* armMotor;

    PIDController* armController;

    Arm();
  public:
    void initDefaultCommand();
    void move(int speed);
    void setSetpoint(int setpoint);
    bool atSetpoint();
    void loop();
    void lock();
    void disablePID();
    void enablePID();
    static Arm* getInstance();
};

#endif // _SUBSYSTEMS_ARM_H_
