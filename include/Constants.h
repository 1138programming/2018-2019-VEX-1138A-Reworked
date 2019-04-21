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
const std::uint8_t rightFrontBaseMotorPort = 19;
const std::uint8_t rightBackBaseMotorPort = 16;
const std::uint8_t leftFrontBaseMotorPort = 15;
const std::uint8_t leftBackBaseMotorPort = 12;

const std::uint8_t flipperPort = 13;

const std::uint8_t flywheelMotorPort = 11;
const std::uint8_t collectorMotorPort = 20;
const std::uint8_t indexerMotorPort = 14;

// Motor gearsets
const pros::motor_gearset_e_t baseMotorGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_gearset_e_t flipperGearset = pros::E_MOTOR_GEARSET_06;
const pros::motor_gearset_e_t flywheelGearset = pros::E_MOTOR_GEARSET_06;
const pros::motor_gearset_e_t collectorGearset = pros::E_MOTOR_GEARSET_06;
const pros::motor_gearset_e_t indexerGearset = pros::E_MOTOR_GEARSET_06;

// Global configurations
const pros::motor_encoder_units_e_t globalEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;
const pros::motor_brake_mode_e_t globalBrakeMode = pros::E_MOTOR_BRAKE_COAST;
const int globalSlewStep = 2 * 127;

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
