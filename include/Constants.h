/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

 #include "abstractBaseClasses/Motor.h"

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 20
#define MAX_FOLLOWERS 3

#define USE_GYRO 1

// Motor ports
const int rightFrontBaseMotorPort = 4;
const int rightBackBaseMotorPort = 8;
const int leftFrontBaseMotorPort = 1;
const int leftBackBaseMotorPort = 3;

const int flipperPort = 2;

const int flywheelMotorPort = 5;
const int frontCollectorMotorPort = 9;
const int middleCollectorMotorPort = 10;

const int gyroPort = 1;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

const double slowSpeedMultiplier = 0.65;

// Global things that we need

#endif
