#include "libIterativeRobot/commands/MiscCommands/ShootAndLoad.h"

#include "libIterativeRobot/Robot.h"

// ADD TO PROSITERATIVEROBOT

ShootAndLoad::ShootAndLoad() {
  runTime = 300;
  this->priority = 10;
  requires(Robot::collector);
  requires(Robot::indexer);
}

bool ShootAndLoad::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ShootAndLoad::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Shoot and load initialized\n");
  startTime = pros::millis();
}

void ShootAndLoad::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Executing delay\n");
  //Robot::robotBase->toggleBaseSpeed();
  Robot::collector->runFrontCollector(127);
  Robot::indexer->runIndexer(80);
}

bool ShootAndLoad::isFinished() {
  printf("startTime is %d and current time is %d\n", startTime, pros::millis());
  return (pros::millis() - startTime) > runTime;; // This is the default va  lue anyways, so this method can be removed
}

void ShootAndLoad::end() {
  // Code that runs when isFinished() returns true.
}

void ShootAndLoad::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  printf("Shoot and load interrupted\n");
}
