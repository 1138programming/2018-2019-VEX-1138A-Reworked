// 6 motors

#ifndef BASE_H
#define BASE_H

#include "main.h"

class Base : public Subsystem {
  private:
    static Base* instance;

    // Sensors on the base
    Gyro gyro;
    Ultrasonic ultrasonic;

    // Left base motors
    Motor* leftFrontBaseMotor;
    Motor* leftMiddleBaseMotor;
    Motor* leftRearBaseMotor;

    // Right base motors
    Motor* rightFrontBaseMotor;
    Motor* rightMiddleBaseMotor;
    Motor* rightRearBaseMotor;

    Encoder baseRightEncoder;
    Encoder baseLeftEncoder;

    PIDController* leftController;
    PIDController* rightController;

    float multiplier;

    int encoderReference;

    Base();
  public:
    void move(int left, int right);
    bool moveTo(int target, int logValue = 750, int threshold = 10);
    bool turnTo(int target, int logValue = 180, int threshold = 10, int direction = 0);
    void setLeftSetpoint(int setpoint);
    void setRightSetpoint(int setpoint);
    void lockLeft();
    void lockRight();
    void loopRight();
    void loopLeft();
    int getLeftSetpoint();
    int getRightSetpoint();
    bool leftAtSetpoint();
    bool rightAtSetpoint();
    void resetGyro();
    int getGyro();
    void resetEncoders();
    int getLeftEncoderValue();
    int getRightEncoderValue();
    //int getUltrasonic();
    void setMultiplier(float multiplier);
    void setReference();
    static Base* getInstance();
};

#endif
