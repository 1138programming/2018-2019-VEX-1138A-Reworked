#include "libIterativeRobot/commands/IndexerCommands/IndexerForward.h"

#include "libIterativeRobot/Robot.h"

IndexerForward::IndexerForward() {
  requires(Robot::indexer);
}

bool IndexerForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IndexerForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void IndexerForward::execute() {
  // Code that runs when this command is scheduled to run

  Robot::indexer->runIndexer(84);
  //Robot::indexer->move(127);
}

bool IndexerForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void IndexerForward::end() {
  // Code that runs when isFinished() returns true.
}

void IndexerForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
