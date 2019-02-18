#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

FlipperBackwardTimed::FlipperBackwardTimed(int mSecs) {
  requires(Robot::flipper);
  runTime = mSecs;
}

bool FlipperBackwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperBackwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void FlipperBackwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipper(-200);
}

bool FlipperBackwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void FlipperBackwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->runFlipper(0);
}

void FlipperBackwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
