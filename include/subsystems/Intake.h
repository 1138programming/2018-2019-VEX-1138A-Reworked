// 1 motor

#ifndef INTAKE_H
#define INTAKE_H

#include "main.h"

class Intake {
  private:
    static Intake* instance;
    Encoder intakeEncoder;
    PIDController* controller;
    Motor* intakeMotor;
    Intake();
  public:
    void move(int speed);
    void setSetpoint(int setpoint);
    void lock();
    int getSetpoint();
    void loop();
    bool atSetpoint();
    int getEncoderValue();
    void resetEncoder();
    static Intake* getInstance();
};

#endif
