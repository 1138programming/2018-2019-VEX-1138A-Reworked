#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForwardTimed.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

MiddleCollectorForwardTimed::MiddleCollectorForwardTimed(int mSecs) {
  requires(Robot::middleCollector);
  runTime = mSecs;
  startTime = pros::millis();
}

bool MiddleCollectorForwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void MiddleCollectorForwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void MiddleCollectorForwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::middleCollector->runMiddleCollector(200);
}

bool MiddleCollectorForwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void MiddleCollectorForwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::middleCollector->runMiddleCollector(0);
}

void MiddleCollectorForwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
