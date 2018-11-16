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

//#define USE_GYRO 1 Not today, Jose

// Motor ports
const int rightFrontBaseMotorPort = 1;
const int rightBackBaseMotorPort = 2;
const int leftFrontBaseMotorPort = 9;
const int leftBackBaseMotorPort = 10;

const int beaterPort = 5;

const int flywheelMotorPort = 7;
const int frontCollectorMotorPort = 8;
const int middleCollectorMotorPort = 6;

const int gyroPort = 1;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

const double slowSpeedMultiplier = 0.65;

// Global things that we need

#endif
