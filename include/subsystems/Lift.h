// 2 motors

#ifndef LIFT_H
#define LIFT_H

#include "main.h"

class Lift {
  private:
    static Lift* instance;
    Encoder liftEncoder;
    PIDController* controller;
    Motor* leftLiftMotor;
    Motor* rightLiftMotor;
    Lift();
  public:
    void move(int speed);
    void setSetpoint(int setpoint);
    void lock();
    int getSetpoint();
    void loop();
    bool atSetpoint();
    int getEncoderValue();
    void resetEncoder();
    static Lift* getInstance();
};

#endif
