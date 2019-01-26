#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"

#include "abstractBaseClasses/Motor.h"

class Base : public libIterativeRobot::Subsystem {
  private:
    Motor* leftFrontBaseMotor;
    Motor* leftBackBaseMotor;
    Motor* rightFrontBaseMotor;
    Motor* rightBackBaseMotor;

    PIDController* leftController;
    PIDController* rightController;

    pros::ADIGyro* baseGyro;

    bool baseReversed = false;
    bool baseSlow = false;
  public:
    void initDefaultCommand();
    void toggleBase();
    void toggleBaseSpeed();
    void move(int left, int right);
    void moveBase(int leftSpeed, int rightSpeed);
    void moveBaseTo(int leftTarget, int rightTarget, int motorSpeed = 0);
    double getLeftVelocity();
    double getRightVelocity();
    void setVoltageLimit(int mV);
    bool baseAtTarget();
    double getGyroValue();
    void resetGyro();

    void setSetpoint(int leftSetpoint, int rightSetpoint);
    void setSetpointRelative(int leftSetpoint, int rightSetpoint);
    int getSetpointLeft();
    int getSetpointRight();
    int getOutputLeft();
    int getOutputRight();
    bool atSetpoint();
    void disablePID();
    void enablePID();
    void setMaxPIDSpeed(int maxSpeed = KMaxMotorSpeed);
    void setMultiplier(float multiplier);
    std::int32_t getLeftEncoder();
    std::int32_t getRightEncoder();
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
