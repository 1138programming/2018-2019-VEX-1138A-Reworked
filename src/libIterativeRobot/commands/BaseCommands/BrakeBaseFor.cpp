#include "libIterativeRobot/commands/BaseCommands/BrakeBaseFor.h"

#include "libIterativeRobot/Robot.h"

BrakeBaseFor::BrakeBaseFor(int timeToRun) {
  requires(Robot::robotBase);
  this->timeToRun = timeToRun;
}

bool BrakeBaseFor::canRun() {
  //printf("BrakeBaseFor(%d);\n", degrees);
  return true; // This is the default value anyways, so this method can be removed
}

void BrakeBaseFor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  this->startTime = pros::millis();
  Robot::robotBase->setBaseMode(pros::E_MOTOR_BRAKE_HOLD);
}

void BrakeBaseFor::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Gyro value: %f\n", Robot::robotBase->getGyroValue());
  //printf("Hello, world!\n");
}

bool BrakeBaseFor::isFinished() {

  return pros::millis() > (timeToRun + startTime);
}

void BrakeBaseFor::end() {
  // Code that runs when isFinished() returns true.
  Robot::robotBase->setBaseMode(pros::E_MOTOR_BRAKE_COAST);
}

void BrakeBaseFor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::robotBase->setBaseMode(pros::E_MOTOR_BRAKE_COAST);
}
