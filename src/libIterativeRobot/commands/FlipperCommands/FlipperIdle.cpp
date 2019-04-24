#include "libIterativeRobot/commands/FlipperCommands/FlipperIdle.h"

#include "libIterativeRobot/Robot.h"

FlipperIdle::FlipperIdle() {
  requires(Robot::flipper);
}

bool FlipperIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::flipper->enable();
  Robot::flipper->setSetpointRelative(0);
}

void FlipperIdle::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Flipper encoder value is %d\n", Robot::flipper->getEncoderValue());
  //Robot::flipper->runFlipper(0);
}

bool FlipperIdle::isFinished() {
  return false; // This is the default va  lue anyways, so this method can be removed
}

void FlipperIdle::end() {
  // Code that runs when isFinished() returns true.
  //printf("Flipper idle is finished\n");
  //Robot::flipper->disable();
}

void FlipperIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  printf("Flipper idle was interrupted\n");
  Robot::flipper->disable();
}
