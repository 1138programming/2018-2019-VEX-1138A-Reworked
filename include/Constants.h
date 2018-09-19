/**
 * @file Constants.h
 * @brief Provides constants used throughout the entire code. Contains user-readable motor names
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_


#include "main.h"
//#include "subsystems/Base.h"
//#include "subsystems/Arm.h"
//#include "subsystems/MobileGoal.h"

#define MAX_MOTORS 10
#define MAX_FOLLOWERS 3

// Motor ports

// Intake motor port
const int intakePort = 1;

// Base motors
const int backRightBasePort = 2; // Reversed
const int frontLeftBasePort = 3;
const int backLeftBasePort = 8;
const int frontRightBasePort = 9; // Reversed

// Cascade motors
const int CascadeMotorOnePort = 5; // Reversed
const int CascadeMotorTwoPort = 7; // Reversed

// Puncher motor
const int puncherPort = 4; // Reversed

// Claw motor
const int clawPort = 10;


// IME Addresses


//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;

#endif
