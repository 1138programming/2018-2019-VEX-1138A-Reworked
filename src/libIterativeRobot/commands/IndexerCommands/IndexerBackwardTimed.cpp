#include "libIterativeRobot/commands/IndexerCommands/IndexerBackwardTimed.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

IndexerBackwardTimed::IndexerBackwardTimed(int mSecs) {
  requires(Robot::indexer);
  runTime = mSecs;
  startTime = pros::millis();
}

bool IndexerBackwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IndexerBackwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void IndexerBackwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::indexer->runIndexer(-200);
}

bool IndexerBackwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void IndexerBackwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::indexer->runIndexer(0);
}

void IndexerBackwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
