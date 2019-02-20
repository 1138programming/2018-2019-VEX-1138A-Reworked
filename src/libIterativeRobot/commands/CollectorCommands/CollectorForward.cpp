#include "libIterativeRobot/commands/CollectorCommands/CollectorForward.h"

#include "libIterativeRobot/Robot.h"

CollectorForward::CollectorForward() {
  requires(Robot::collector);
}

bool CollectorForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CollectorForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor

  printf("Testing");
}

void CollectorForward::execute() {
  // Code that runs when this command is scheduled to run

  Robot::collector->runFrontCollector(200);
  printf("Testing");
  //Robot::collector->runMiddleCollector(200);
  //if (Robot::collector->getUltrasonic() < 95 && Robot::collector->getUltrasonic() != -1) {
  //  Robot::collector->runMiddleCollector(0);
  //}
}

bool CollectorForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void CollectorForward::end() {
  // Code that runs when isFinished() returns true.
}

void CollectorForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
