#include "libIterativeRobot/commands/FlipperCommands/FlipperTo.h"

#include "libIterativeRobot/Robot.h"

FlipperTo::FlipperTo(int target) {
  this->target = target;
  requires(Robot::flipper);
}

bool FlipperTo::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlipperTo::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Enabling flipper PID\n");
  Robot::flipper->setSetpoint(target);
  Robot::flipper->enable();
}

void FlipperTo::execute() {
  // Code that runs when this command is scheduled to run

  printf("Flipper encoder value is %d\n", Robot::flipper->getEncoderValue());
  //printf("Moving flipper to %d\n", target);
  //Robot::flipper->runFlipper(-42);
}

bool FlipperTo::isFinished() {
  return Robot::flipper->atTarget(); // This is the default va  lue anyways, so this method can be removed
}

void FlipperTo::end() {
  // Code that runs when isFinished() returns true.
  printf("FlipperTo finished, disabling flipper PID\n");
  Robot::flipper->disable();
  Robot::flipper->runFlipper(0);
}

void FlipperTo::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::flipper->disable();
  Robot::flipper->runFlipper(0);
}
