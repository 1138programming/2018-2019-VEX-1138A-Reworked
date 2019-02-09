#include "libIterativeRobot/commands/FlipperBackwardsTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

FlipperBackwardsTimed::FlipperBackwardsTimed(int speed, int mSecs) {
  requires(Robot::flipper);
  speed = speed;
  runTime = mSecs;
}

bool FlipperBackwardsTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperBackwardsTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void FlipperBackwardsTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipper(-200);
}

bool FlipperBackwardsTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void FlipperBackwardsTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->runFlipper(0);
}

void FlipperBackwardsTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
