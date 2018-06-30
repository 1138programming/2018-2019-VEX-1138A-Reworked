// 2 motors, y-cabled

#ifndef PUNCHER_H
#define PUNCHER_H

#include "main.h"

class Puncher {
  private:
    static Puncher* instance;
    Encoder puncherEncoder;
    PIDController* controller;
    Motor* puncherMotor;
    Puncher();
  public:
    void move(int speed);
    void setSetpoint(int setpoint);
    void lock();
    int getSetpoint();
    void loop();
    bool atSetpoint();
    int getEncoderValue();
    void resetEncoder();
    static Puncher* getInstance();
};

#endif
