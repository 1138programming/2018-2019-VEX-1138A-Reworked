#include "libIterativeRobot/commands/CollectorMiddleBackwardsTimed.h"
#include "libIterativeRobot/Robot.h"

#include "api.h"

CollectorMiddleBackwardsTimed::CollectorMiddleBackwardsTimed(int mSecs) {
  requires(Robot::middleCollector);
  runTime = mSecs;
  startTime = pros::millis();
}

bool CollectorMiddleBackwardsTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorMiddleBackwardsTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void CollectorMiddleBackwardsTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::middleCollector->runMiddleCollector(-200);
}

bool CollectorMiddleBackwardsTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void CollectorMiddleBackwardsTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::middleCollector->runMiddleCollector(0);
}

void CollectorMiddleBackwardsTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
