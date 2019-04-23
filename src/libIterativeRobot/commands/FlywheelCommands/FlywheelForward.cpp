#include "libIterativeRobot/commands/FlywheelCommands/FlywheelForward.h"

#include "libIterativeRobot/Robot.h"

FlywheelForward::FlywheelForward() {
  requires(Robot::flywheel);
}

bool FlywheelForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlywheelForward::execute() {
  // Code that runs when this command is scheduled to run
  // printf("Flywheel forward executed\n");
  // if (Robot::flywheel->getFlywheelVelocity() < 0) {
  //   Robot::flywheel->setFlywheel(0);
  // } else {
  //   Robot::flywheel->setFlywheel(-116);
  // }
}

bool FlywheelForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelForward::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
