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
const int rightFrontBaseMotorPort = 19;
const int rightBackBaseMotorPort = 16;
const int leftFrontBaseMotorPort = 15;
const int leftBackBaseMotorPort = 12;

const int flipperPort = 13;

const int flywheelMotorPort = 11;
const int frontCollectorMotorPort = 20;
const int middleCollectorMotorPort = 14;

// Analog Ports
const int gyroPort = 3;
const int ultrasonicEchoPort = 1;
const int ultrasonicPingPort = 2;

const int visionPort = 7;

//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct

const double slowSpeedMultiplier = 0.65;

// Global things that we need

#endif
