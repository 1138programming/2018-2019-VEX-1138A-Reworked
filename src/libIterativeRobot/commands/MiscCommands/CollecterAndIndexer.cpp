#include "libIterativeRobot/commands/MiscCommands/CollectorAndIndexer.h"

#include "libIterativeRobot/Robot.h"

CollectorAndIndexer::CollectorAndIndexer() {
  this->priority = 10;
  requires(Robot::collector);
  requires(Robot::indexer);
}

bool CollectorAndIndexer::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorAndIndexer::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::collector->runFrontCollector(100);
  if (Robot::indexer->getUltrasonic() > 80 || Robot::indexer->getUltrasonic() == -1) {
    Robot::indexer->runIndexer(60);
  } else {
    Robot::indexer->runIndexer(0);
  }
  printf("Ultrasonic value is %d\n", Robot::indexer->getUltrasonic());
}

void CollectorAndIndexer::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Executing delay\n");
  //Robot::robotBase->toggleBaseSpeed();
}

bool CollectorAndIndexer::isFinished() {
  return true;
}

void CollectorAndIndexer::end() {
  // Code that runs when isFinished() returns true.
}

void CollectorAndIndexer::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
