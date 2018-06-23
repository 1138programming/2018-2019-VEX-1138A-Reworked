#ifndef _SUBSYSTEMS_PIDCONTROLLER_H_
#define _SUBSYSTEMS_PIDCONTROLLER_H_

#include "Motor.h"

class PIDController {
  private:
    float kP = 0;
    float kI = 0;
    float kD = 0;
    Motor* outputMotor;
    float integral = 0;
    float derivative = 0;
    int error = 0;
    int previousError = 0;
    int output = 0;
    int setpoint = 0;
    int currSensorValue = 0;
    int threshold = 15; // Default value
    float deltaTime = 0;
    int lastTime = 0;
  public:
    PIDController(Motor* motorChannel, float kP = 1, float kI = 0, float kD = 0);
    void setKp(float kP);
    void setKi(float kI);
    void setKd(float kD);
    void setSetpoint(int setpoint);
    int getSetpoint();
    void sensorValue(int value);
    void setThreshold(int threshold);
    bool atSetpoint();
    void loop();
};

#endif
