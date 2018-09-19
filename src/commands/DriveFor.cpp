#include "commands/DriveFor.h"
#include "Robot.h"

DriveFor::DriveFor(unsigned int duration, int leftSpeed, int rightSpeed) {
  this->duration = duration;
  this->leftSpeed = leftSpeed;
  this->rightSpeed = rightSpeed;

  requires(Robot::base);
  this->priority = 1;
}

bool DriveFor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void DriveFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  // Note: initialize() will be called before execute any time this command
  // tries to run, since isFinished() returns true.
  startTime = millis();
}

void DriveFor::execute() {
  // Code that runs when this command is scheduled to run
  Robot::base->move(leftSpeed, rightSpeed);
}

bool DriveFor::isFinished() {
  return millis() > (startTime + duration); // This is the default value anyways, so this method can be removed
}

void DriveFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::base->move(0, 0);
}

void DriveFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::base->move(0, 0);
}
