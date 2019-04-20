#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"

#include "abstractBaseClasses/Motor.h"
#include "abstractBaseClasses/PIDController.h"

class Base : public libIterativeRobot::Subsystem {
  private:
    Motor* leftFrontBaseMotor;
    Motor* leftBackBaseMotor;
    Motor* rightFrontBaseMotor;
    Motor* rightBackBaseMotor;

    pros::ADIGyro* baseGyro;

    PIDController* basePIDController;

    pros::Vision* baseVision;

    bool baseReversed = false;
    bool baseSlow = false;

    int baseEncoderDrift = 0;
  public:
    void initDefaultCommand();
    void setBaseMode(pros::motor_brake_mode_e motorMode);
    void toggleBase();
    void toggleBaseSpeed();
    void moveBase(int left, int right);
    void moveBaseTo(int leftTarget, int rightTarget, int motorSpeed = 0);
    void moveBaseForward(int target, int motorSpeed = 0);
    void setLinearTarget(int target, bool absolute = false);
    void updateLinearMovement();
    bool baseAtTarget();
    bool baseAtLinearTarget();
    double getGyroValue();
    void resetGyro();
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
