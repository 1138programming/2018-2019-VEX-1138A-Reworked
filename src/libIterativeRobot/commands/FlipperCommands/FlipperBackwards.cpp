#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwards.h"

#include "libIterativeRobot/Robot.h"

FlipperBackwards::FlipperBackwards() {
  this->priority = 20;
  requires(Robot::flipper);
}

bool FlipperBackwards::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperBackwards::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  //printf("Flipper backwards init\n");
}

void FlipperBackwards::execute() {
  // Code that runs when this command is scheduled to run
  //Robot::flipper->disable();
  Robot::flipper->runFlipper(-80);
  //printf("Flipper backwards exec\n");
}

bool FlipperBackwards::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlipperBackwards::end() {
  // Code that runs when isFinished() returns true.
  //printf("Flipper backwards end\n");
}

void FlipperBackwards::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  //printf("Flipper backwards interrpted\n");
}
