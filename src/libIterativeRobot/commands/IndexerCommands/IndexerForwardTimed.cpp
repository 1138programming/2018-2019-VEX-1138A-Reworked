#include "libIterativeRobot/commands/IndexerCommands/IndexerForwardTimed.h"

#include "libIterativeRobot/Robot.h"

#include "api.h"

IndexerForwardTimed::IndexerForwardTimed(int mSecs) {
  requires(Robot::indexer);
  runTime = mSecs;
  startTime = pros::millis();
}

bool IndexerForwardTimed::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IndexerForwardTimed::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  startTime = pros::millis();
}

void IndexerForwardTimed::execute() {
  // Code that runs when this command is scheduled to run

  Robot::indexer->runIndexer(84);
}

bool IndexerForwardTimed::isFinished() {
  return (pros::millis() - startTime) > runTime;
}

void IndexerForwardTimed::end() {
  // Code that runs when isFinished() returns true.
  Robot::indexer->runIndexer(0);
}

void IndexerForwardTimed::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
