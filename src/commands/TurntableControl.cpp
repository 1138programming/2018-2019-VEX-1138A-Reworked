#include "commands/TurntableControl.h"
#include "Robot.h"
#include "Constants.h"

TurntableControl::TurntableControl() {
  requires(Robot::turntable);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool TurntableControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void TurntableControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void TurntableControl::execute() {
  // Code that runs when this command is scheduled to run
  printf("Turntable default command is running\n");
  turntableUpButton = joystickGetDigital(1, 5, JOY_UP);
  turntableDownButton = joystickGetDigital(1, 5, JOY_DOWN);

  if (turntableUpButton)
    Robot::turntable->move(KMaxMotorSpeed);
  else if (turntableDownButton)
    Robot::turntable->move(-KMaxMotorSpeed);
  else
    Robot::turntable->move(0);
}

bool TurntableControl::isFinished() {
  return true;
}

void TurntableControl::end() {
  // Code that runs when isFinished() returns true.
}

void TurntableControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
