#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

DriveLinear::DriveLinear(int target) {
  requires(Robot::robotBase);
  this->leftTarget = target;
  this->rightTarget = target;
  this->motorSpeed = 0;
  this->startTime = pros::millis();
}

DriveLinear::DriveLinear(int rightTarget, int leftTarget) {
  requires(Robot::robotBase);
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->motorSpeed = motorSpeed;
  this->startTime = pros::millis();
}

bool DriveLinear::canRun() {
  //printf("DriveLinear(%d)\n", target);
  return true; // This is the default value anyways, so this method can be removed
}

void DriveLinear::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //this->endTime = pros::millis() + ((abs(target) / (motorSpeed ? motorSpeed : 150)) * 150) + 500;
  //Robot::robotBase->resetGyro();
  Robot::robotBase->initLinearMovement(leftTarget, rightTarget);
  //Robot::robotBase->moveBaseForward(target, motorSpeed);
}

void DriveLinear::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Executing\n");
  Robot::robotBase->updateLinearMovement();
}

bool DriveLinear::isFinished() {
  //printf("Here!\n");
  //printf("At linear target is %d\n", Robot::robotBase->baseAtLinearTarget());
  return Robot::robotBase->baseAtLinearTarget();
  //if ((pros::millis() - startTime) < 250) return false;
  //return Robot::robotBase->baseAtLinearTarget() || pros::millis() > endTime; // This is the default value anyways, so this method can be removed
}

void DriveLinear::end() {
  // Code that runs when isFinished() returns true.
  printf("Done\n");
  Robot::robotBase->stopLinearMovement();
  Robot::robotBase->moveBase(0, 0);
}

void DriveLinear::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::robotBase->stopLinearMovement();
  Robot::robotBase->moveBase(0, 0);
}
