#include "libIterativeRobot/commands/FlipperIdle.h"
#include "libIterativeRobot/Robot.h"

FlipperIdle::FlipperIdle() {
  requires(Robot::flipper);
}

bool FlipperIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlipperIdle::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipperForward(0);
}

bool FlipperIdle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlipperIdle::end() {
  // Code that runs when isFinished() returns true.
}

void FlipperIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
