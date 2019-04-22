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

    PIDController* gyroPID;
    PIDController* leftPosPID;
    PIDController* rightPosPID;
    PIDController* leftVelPID;
    PIDController* rightVelPID;

    pros::Vision* baseVision;

    int leftLastPos = 0;
    int rightLastPos = 0;
    int leftVel = 0;
    int rightVel = 0;
    std::uint32_t lastTime = 0;

    bool baseReversed = false;
    bool baseSlow = false;

    int baseEncoderDrift = 0;
  public:
    void initDefaultCommand();
    void setBaseMode(pros::motor_brake_mode_e motorMode);
    void toggleBase();
    void toggleBaseSpeed();
    void moveBase(int left, int right);
    //void moveBaseTo(int leftTarget, int rightTarget, int motorSpeed = 0);
    //void moveBaseForward(int target, int motorSpeed = 0);
    void initLinearMovement(int leftTarget, int rightTarget, bool absolute = false);
    void updateLinearMovement();
    //bool baseAtTarget();
    bool baseAtLinearTarget();
    void stopLinearMovement();

    void initTurnWithGyro(int target, bool absolute = false);
    void updateTurnWithGyro();
    bool atTurnTarget();
    void stopTurnWithGyro();

    double getLeftEncoderValue();
    double getRightEncoderValue();
    double getGyroValue();
    void resetEncoders();
    void resetGyro();
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
