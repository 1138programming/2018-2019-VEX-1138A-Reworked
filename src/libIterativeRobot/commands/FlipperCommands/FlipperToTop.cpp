#include "libIterativeRobot/commands/FlipperCommands/FlipperToTop.h"

#include "libIterativeRobot/Robot.h"

FlipperToTop::FlipperToTop() {
  requires(Robot::flipper);
}

bool FlipperToTop::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperToTop::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlipperToTop::execute() {
  // Code that runs when this command is scheduled to run

  Robot::flipper->runFlipper(-200);
}

bool FlipperToTop::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlipperToTop::end() {
  // Code that runs when isFinished() returns true.
}

void FlipperToTop::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
