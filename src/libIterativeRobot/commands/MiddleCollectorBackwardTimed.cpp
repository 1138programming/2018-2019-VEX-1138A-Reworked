#include "libIterativeRobot/commands/MiddleCollectorBackwardTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

MiddleCollectorBackwardTimed::MiddleCollectorBackwardTimed(int mSecs) {
  requires(Robot::collector);
  runTime = mSecs;
  startTime = pros::millis();
}

bool MiddleCollectorBackwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MiddleCollectorBackwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void MiddleCollectorBackwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runMiddleCollector(-200);
}

bool MiddleCollectorBackwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void MiddleCollectorBackwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::collector->runMiddleCollector(0);
}

void MiddleCollectorBackwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
