#include "libIterativeRobot/commands/IndexerCommands/IndexerBackwards.h"

#include "libIterativeRobot/Robot.h"

IndexerBackwards::IndexerBackwards() {
  requires(Robot::indexer);
}

bool IndexerBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IndexerBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void IndexerBackwards::execute() {
  // Code that runs when this command is scheduled to run

  Robot::indexer->runIndexer(-200);
  //Robot::indexer->move(-127);
}

bool IndexerBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void IndexerBackwards::end() {
  // Code that runs when isFinished() returns true.
}

void IndexerBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
