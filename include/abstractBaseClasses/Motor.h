#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"

enum Ports {
  A = 22,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
};

enum MotorType {
  v4,
  v5,
};

class Motor {
  private:
    const static int slewStep = 14;

    std::uint8_t channel;
    pros::motor_gearset_e_t gearset;
    pros::motor_encoder_units_e_t encoderUnits;
    int targetSpeed;
    int speed;
    float multiplier;
    Motor(std::uint8_t channel, MotorType motorType);
    Motor* followers[MAX_FOLLOWERS];
    unsigned int numFollowers;
    Motor* master;
    MotorType motorType;
    pros::Motor* v5Motor;
    pros::ADIMotor* v4Motor;
    pros::ADIEncoder* encoder;
    bool following;
    void setMaster(Motor* motor);
    static Motor* motorInstances[MAX_MOTORS];
    static const pros::motor_gearset_e_t defaultGearset;
    static const pros::motor_encoder_units_e_t defaultEncoderUnits;
  public:
    MotorType getMotorType();
    void setSpeed(int speed);
    int getSpeed();
    void reverse();
    void setMultiplier(float multiplier);
    void addFollower(Motor* motor);
    static void init();
    int getChannel();
    void updateSlewRate();
    pros::Motor* getMotorObject();
    void move();
    void setEncoder(pros::ADIEncoder* encoder);
    std::int32_t getEncoderValue();
    static void periodicUpdate();
    static Motor* getMotor(int motorPort);
    static Motor* getMotor(Ports motorPort);
};

#endif
