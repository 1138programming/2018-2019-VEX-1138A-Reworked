#include "libIterativeRobot/commands/IndexerCommands/IndexerIdle.h"

#include "libIterativeRobot/Robot.h"

IndexerIdle::IndexerIdle() {
  requires(Robot::indexer);
}

bool IndexerIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IndexerIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void IndexerIdle::execute() {
  // Code that runs when this command is scheduled to run

  Robot::indexer->runIndexer(0);
}

bool IndexerIdle::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void IndexerIdle::end() {
  // Code that runs when isFinished() returns true.
}

void IndexerIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
