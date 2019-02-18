#include "libIterativeRobot/commands/FlipperCommands/FlipperForward.h"

#include "libIterativeRobot/Robot.h"

FlipperForward::FlipperForward() {
  requires(Robot::flipper);
}

bool FlipperForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlipperForward::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipper(200);
}

bool FlipperForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlipperForward::end() {
  // Code that runs when isFinished() returns true.
}

void FlipperForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
