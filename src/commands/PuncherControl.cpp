#include "commands/PuncherControl.h"
#include "Robot.h"
#include "Constants.h"

PuncherControl::PuncherControl() {
  requires(Robot::puncher);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool PuncherControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void PuncherControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void PuncherControl::execute() {
  // Code that runs when this command is scheduled to run
  printf("Puncher default command is running\n");
  puncherUpButton = joystickGetDigital(1, 6, JOY_UP);
  puncherDownButton = joystickGetDigital(1, 6, JOY_DOWN);

  if (puncherUpButton)
    Robot::puncher->move(KMaxMotorSpeed);
  else if (puncherDownButton)
    Robot::puncher->move(-KMaxMotorSpeed);
  else
    Robot::puncher->move(0);
}

bool PuncherControl::isFinished() {
  return true;
}

void PuncherControl::end() {
  // Code that runs when isFinished() returns true.
}

void PuncherControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
