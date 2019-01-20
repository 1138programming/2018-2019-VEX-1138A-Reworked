#include "libIterativeRobot/commands/FlipperForwardTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

FlipperForwardTimed::FlipperForwardTimed(int mSecs) {
  requires(Robot::flipper);
  runTime = mSecs;
}

bool FlipperForwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperForwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void FlipperForwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipper(200);
}

bool FlipperForwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void FlipperForwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->runFlipper(0);
}

void FlipperForwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
