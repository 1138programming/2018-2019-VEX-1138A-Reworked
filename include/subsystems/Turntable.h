// 1 motor

#ifndef TURNTABLE_H
#define TURNTABLE_H

#include "main.h"

class Turntable : public Subsystem {
  private:
    static Turntable* instance;
    Encoder turntableEncoder;
    PIDController* controller;
    Motor* turntableMotor;
    Turntable();
  public:
    void move(int speed);
    void setSetpoint(int setpoint);
    void lock();
    int getSetpoint();
    void loop();
    bool atSetpoint();
    int getEncoderValue();
    void resetEncoder();
    static Turntable* getInstance();
};

#endif
