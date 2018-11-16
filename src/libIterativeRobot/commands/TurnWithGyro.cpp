#include "libIterativeRobot/commands/TurnWithGyro.h"
#include "libIterativeRobot/Robot.h"

TurnWithGyro::TurnWithGyro(int turnDegrees) {
  requires(Robot::robotBase);
  this->degrees = turnDegrees;
  this->motorSpeed = 0;
}

TurnWithGyro::TurnWithGyro(int turnDegrees, int motorSpeed) {
  requires(Robot::robotBase);
  this->degrees = turnDegrees;
  this->motorSpeed = motorSpeed;
}

bool TurnWithGyro::canRun() {
  printf("TurnWithGyro(%d);\n", degrees);
  return true; // This is the default value anyways, so this method can be removed
}

void TurnWithGyro::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::robotBase->resetGyro();
}

void TurnWithGyro::execute() {
  // Code that runs when this command is scheduled to run
  int motorSpeed = this->motorSpeed ? this->motorSpeed : 25;
  //if (abs(degrees - Robot::robotBase->getGyroValue()) < 900) {
  //  motorSpeed = motorSpeed * log(-abs(degrees - Robot::robotBase->getGyroValue()) + 900);
  //}
  // printf("Gyro value\n");
  // pros::delay(10);
  if (degrees > Robot::robotBase->getGyroValue()) {
    Robot::robotBase->moveBase(-motorSpeed, motorSpeed);
  } else if (degrees < Robot::robotBase->getGyroValue()) {
    Robot::robotBase->moveBase(motorSpeed, -motorSpeed);
  }
}

bool TurnWithGyro::isFinished() {
  return abs(degrees - Robot::robotBase->getGyroValue()) < 50; // This is the default va  lue anyways, so this method can be removed
}

void TurnWithGyro::end() {
  // Code that runs when isFinished() returns true.
  Robot::robotBase->moveBase(0, 0);
}

void TurnWithGyro::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
