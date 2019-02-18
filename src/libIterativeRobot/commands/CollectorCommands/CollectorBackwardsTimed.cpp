#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

CollectorBackwardsTimed::CollectorBackwardsTimed(int mSecs) {
  requires(Robot::collector);
  runTime = mSecs;
}

bool CollectorBackwardsTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorBackwardsTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void CollectorBackwardsTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runFrontCollector(-200);
}

bool CollectorBackwardsTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void CollectorBackwardsTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::collector->runFrontCollector(0);
}

void CollectorBackwardsTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
