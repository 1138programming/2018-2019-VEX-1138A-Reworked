#include "libIterativeRobot/commands/BaseCommands/ResetGyro.h"

#include "libIterativeRobot/Robot.h"

ResetGyro::ResetGyro() {
  requires(Robot::robotBase);
}

bool ResetGyro::canRun() {
  //printf("ResetGyro(%d);\n", degrees);
  return true; // This is the default value anyways, so this method can be removed
}

void ResetGyro::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::robotBase->resetGyro();
}

void ResetGyro::execute() {
  // Code that runs when this command is scheduled to run
}

bool ResetGyro::isFinished() {
  return true;
}

void ResetGyro::end() {
  // Code that runs when isFinished() returns true.
}

void ResetGyro::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
