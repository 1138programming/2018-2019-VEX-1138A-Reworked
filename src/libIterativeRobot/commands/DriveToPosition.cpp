#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

/*DriveToPosition::DriveToPosition(int leftTarget, int rightTarget) {
  requires(Robot::robotBase);
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->motorSpeed = 0;
  this->mV = 12000;
}*/

DriveToPosition::DriveToPosition(int leftTarget, int rightTarget, int motorSpeed, int mV) {
  requires(Robot::robotBase);
  this->leftTarget = leftTarget;
  this->rightTarget = rightTarget;
  this->motorSpeed = motorSpeed;
  this->mV = mV;
}

bool DriveToPosition::canRun() {
  //printf("DriveToPosition(%d, %d)\n", leftTarget, rightTarget);
  return true; // This is the default value anyways, so this method can be removed
}

void DriveToPosition::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //this->endTime = pros::millis() + ((((abs(leftTarget) + abs(rightTarget)) / 2) / (motorSpeed ? motorSpeed : 150)) * 150);
  //printf("End time is %d\n", endTime);
  printf("DriveToPosition(%d, %d)\n", this->leftTarget, this->rightTarget);
  Robot::robotBase->setVoltageLimit(mV);
  Robot::robotBase->moveBaseTo(leftTarget, rightTarget, motorSpeed);
}

void DriveToPosition::execute() {
  // Code that runs when this command is scheduled to run
  printf("Velocities are %d and %d\n", Robot::robotBase->getLeftVelocity(), Robot::robotBase->getRightVelocity());
}

bool DriveToPosition::isFinished() {
  //printf("Base at target: %d\n", Robot::robotBase->baseAtTarget());
  return Robot::robotBase->baseAtTarget()/* || pros::millis() > endTime || (pros::c::adi_digital_read(5) && pros::c::adi_digital_read(6))*/; // This is the default value anyways, so this method can be removed
}

void DriveToPosition::end() {
  // Code that runs when isFinished() returns true.
  Robot::robotBase->moveBase(0, 0);
  Robot::robotBase->setVoltageLimit(12000);
}

void DriveToPosition::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::robotBase->setVoltageLimit(12000);
}
