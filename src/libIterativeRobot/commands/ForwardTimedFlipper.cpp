#include "libIterativeRobot/commands/ForwardTimedFlipper.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

ForwardTimedFlipper::ForwardTimedFlipper(int mSecs) {
  requires(Robot::flipper);
  runTime = mSecs;
}

bool ForwardTimedFlipper::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ForwardTimedFlipper::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void ForwardTimedFlipper::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipper(200);
}

bool ForwardTimedFlipper::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void ForwardTimedFlipper::end() {
  // Code that runs when isFinished() returns true.
  Robot::flipper->runFlipper(0);
}

void ForwardTimedFlipper::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
