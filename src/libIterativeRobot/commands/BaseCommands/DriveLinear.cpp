#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

DriveLinear::DriveLinear(int target) {
  requires(Robot::robotBase);
  this->target = target;
  this->motorSpeed = 0;
  this->startTime = pros::millis();
  this->priority = 3;
}

DriveLinear::DriveLinear(int target, int motorSpeed) {
  requires(Robot::robotBase);
  this->target = target;
  this->motorSpeed = motorSpeed;
  this->startTime = pros::millis();
  this->priority = 3;
}

bool DriveLinear::canRun() {
  //printf("DriveLinear(%d)\n", target);
  return true; // This is the default value anyways, so this method can be removed
}

void DriveLinear::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("DriveLinear(%d)\n", target);
  this->endTime = pros::millis() + ((abs(target) / (motorSpeed ? motorSpeed : 150)) * 150) + 500;
  Robot::robotBase->moveBaseForward(target, motorSpeed);
}

void DriveLinear::execute() {
  // Code that runs when this command is scheduled to run
  printf("Executing?\n");
  Robot::robotBase->updateLinearMovement();
  printf("And it executed\n");
}

bool DriveLinear::isFinished() {
  printf("Here!\n");
  if ((pros::millis() - startTime) < 250) return false;
  return Robot::robotBase->baseAtLinearTarget() || pros::millis() > endTime; // This is the default value anyways, so this method can be removed
}

void DriveLinear::end() {
  // Code that runs when isFinished() returns true.
  Robot::robotBase->moveBase(0, 0);
}

void DriveLinear::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
