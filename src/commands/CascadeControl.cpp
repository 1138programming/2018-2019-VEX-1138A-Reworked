#include "commands/CascadeControl.h"
#include "Robot.h"
#include "Constants.h"

CascadeControl::CascadeControl() {
  requires(Robot::cascade);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool CascadeControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void CascadeControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void CascadeControl::execute() {
  // Code that runs when this command is scheduled to run
  printf("Cascade default command is running\n");
  cascadeUpButton = joystickGetDigital(2, 7, JOY_UP);
  cascadeDownButton = joystickGetDigital(2, 7, JOY_DOWN);

  if (cascadeUpButton)
    Robot::cascade->move(KMaxMotorSpeed);
  else if (cascadeDownButton)
    Robot::cascade->move(-KMaxMotorSpeed);
  else
    Robot::cascade->move(0);
}

bool CascadeControl::isFinished() {
  return true;
}

void CascadeControl::end() {
  // Code that runs when isFinished() returns true.
}

void CascadeControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
