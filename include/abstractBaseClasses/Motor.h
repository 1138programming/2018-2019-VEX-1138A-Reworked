#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"

class Motor {
  private:
    const static int slewStep = 14;

    int channel;
    int targetSpeed;
    int speed;
    float multiplier;
    Motor(int channel);
    Motor* followers[MAX_FOLLOWERS];
    unsigned int numFollowers;
    Motor* master;
    bool following;
    void setMaster(Motor* motor);
    static Motor* motorInstances[MAX_MOTORS];
  public:
    void setSpeed(int speed);
    int getSpeed();
    void reverse();
    void setMultiplier(float multiplier);
    void addFollower(Motor* motor);
    static void init();
    int getChannel();
    void updateSlewRate();
    static void periodicUpdate();
    static Motor* getMotor(int motorPort);
};

#endif
