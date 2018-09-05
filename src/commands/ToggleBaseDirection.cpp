#include "commands/ToggleBaseDirection.h"
#include "Robot.h"
#include "Constants.h"

ToggleBaseDirection::ToggleBaseDirection() {
  requires(Robot::base);
  this->priority = DefaultCommandPriority + 1; // Lowest priority
}

bool ToggleBaseDirection::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void ToggleBaseDirection::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  baseToggleButton = joystickGetDigital(1, 5, JOY_UP);
}

void ToggleBaseDirection::execute() {
  // Code that runs when this command is scheduled to run
  printf("Toggling base direction...");
  Robot::base->setBaseReversed(!Robot::base->getReversed());
}

bool ToggleBaseDirection::isFinished() {
  return true;
}

void ToggleBaseDirection::end() {
  // Code that runs when isFinished() returns true.
}

void ToggleBaseDirection::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
