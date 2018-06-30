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

#define DEFAULT_TASK_TIME 10000
#define DELAY_TIME 10
#define MAX_MOTORS 10
#define MAX_FOLLOWERS 3

// Motor ports
// Left base motor ports
const int leftFrontBasePort = 1;
const int leftMiddleBasePort = 2;
const int leftRearBasePort = 3;

// Right base motor ports
const int rightFrontBasePort = 10;
const int rightMiddleBasePort = 9;
const int rightRearBasePort = 8;

// Collector motor port
const int puncherPort = 4;

// Intake motor port
const int intakePort = 5;

// Turntable motor ports // Capflip
const int turntablePort = 6;

// Lift motor ports (6 bar)
const int liftPort = 7;


// IME Addresses


//Motor and encoder constants
const int KMaxMotorSpeed = 127;
const int KMaxJoystickValue = 127;
const int encoderTicks = 360; // Encoder ticks in one revolution
const float rotationsPerInch = 31.400156410256; // TODO check if this is correct


// Analog Sensors
const int gyroPort = 1;


// Digital Sensors
//const int ultrasonicPing = 4;
//const int ultrasonicEcho = 5;
const int baseRightEncoderTopPort = 2;
const int baseRightEncoderBottomPort = 1;
const int baseLeftEncoderTopPort = 4;
const int baseLeftEncoderBottomPort = 3;
const int intakeEncoderTopPort = 6;
const int intakeEncoderBottomPort = 5;
const int liftEncoderTopPort = 8;
const int liftEncoderBottomPort = 7;
const int turntableEncoderTopPort = 10;
const int turntableEncoderBottomPort = 9;
const int puncherEncoderTopPort = 12;
const int puncherEncoderBottomPort = 11;



// Global things that we need

#endif
