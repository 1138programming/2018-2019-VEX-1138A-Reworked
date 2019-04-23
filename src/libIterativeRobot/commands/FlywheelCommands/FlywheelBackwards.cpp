#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"

#include "libIterativeRobot/Robot.h"

FlywheelBackwards::FlywheelBackwards() {
  requires(Robot::flywheel);
}

bool FlywheelBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  if (on)
    on = false;
  else
    on = true;
}

void FlywheelBackwards::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Flywheel backward executed\n");
  if (on) {
    Robot::flywheel->setFlywheel(116);
  } else {
    Robot::flywheel->setFlywheel(0);
  }
}

bool FlywheelBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelBackwards::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
