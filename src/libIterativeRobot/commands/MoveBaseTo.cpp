#include "libIterativeRobot/commands/MoveBaseTo.h"
#include "libIterativeRobot/Robot.h"
#include "Constants.h"

MoveBaseTo::MoveBaseTo(int leftTarget, int rightTarget, int maxSpeed, int timeout, bool absolute) {
  // Set requirements
  requires(Robot::robotBase);

  // Initialize variables
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->maxSpeed = maxSpeed;
  this->absolute = absolute;
  this->timeout = timeout;

  // Set priority
  this->priority = 1;
}

bool MoveBaseTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MoveBaseTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  Robot::robotBase->setMaxPIDSpeed(maxSpeed);

  Robot::robotBase->enablePID();
  if (absolute)
    Robot::robotBase->setSetpoint(leftTarget, rightTarget);
  else
    Robot::robotBase->setSetpointRelative(leftTarget, rightTarget);

  startTime = pros::millis();
}

void MoveBaseTo::execute() {
  //printf("Moving base to: %d\n", target);
  printf("Left side error is %d, right side error is %d. Left side output is %d, right side output is %d\n", Robot::robotBase->getSetpointLeft() - Robot::robotBase->getLeftEncoder(), Robot::robotBase->getSetpointRight() - Robot::robotBase->getRightEncoder(), Robot::robotBase->getOutputLeft(), Robot::robotBase->getOutputRight());
  printf("Left side output is %d, right side output is %d\n", Robot::robotBase->getOutputLeft(), Robot::robotBase->getOutputRight());
}

bool MoveBaseTo::isFinished() {
  return Robot::robotBase->atSetpoint() || pros::millis() - startTime >= timeout;
  //return Robot::robotBase->atSetpoint();
  //return false;
}

void MoveBaseTo::end() {
  // Code that runs when isFinished() returns true.
  printf("At target\n");
  Robot::robotBase->disablePID();
}

void MoveBaseTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::robotBase->disablePID();
}
