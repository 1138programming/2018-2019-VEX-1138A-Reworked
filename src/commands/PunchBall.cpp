#include "commands/PunchBall.h"
#include "Robot.h"
#include "Constants.h"

PunchBall::PunchBall() {
  requires(Robot::puncher);
  this->priority = 1;
}

bool PunchBall::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void PunchBall::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = millis();
}

void PunchBall::execute() {
  // Code that runs when this command is scheduled to run
  Robot::puncher->move(-KMaxMotorSpeed);
}

bool PunchBall::isFinished() {
  return millis() > (startTime + duration);
}

void PunchBall::end() {
  // Code that runs when isFinished() returns true.
  Robot::puncher->move(0);
}

void PunchBall::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::puncher->move(0);
}
