#include "libIterativeRobot/commands/BeaterForwardTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

BeaterForwardTimed::BeaterForwardTimed(int mSecs) {
  requires(Robot::beater);
  runTime = mSecs;
}

bool BeaterForwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void BeaterForwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void BeaterForwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::beater->runBeater(-200);
}

bool BeaterForwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void BeaterForwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::beater->runBeater(0);
}

void BeaterForwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
