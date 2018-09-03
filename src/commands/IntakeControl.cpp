#include "commands/IntakeControl.h"
#include "Robot.h"
#include "Constants.h"

IntakeControl::IntakeControl() {
  requires(Robot::intake);
  this->priority = DefaultCommandPriority; // Lowest priority
}

bool IntakeControl::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void IntakeControl::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void IntakeControl::execute() {
  // Code that runs when this command is scheduled to run
  printf("Intake default command is running\n");
  intakeUpButton = joystickGetDigital(1, 7, JOY_UP);
  intakeDownButton = joystickGetDigital(1, 7, JOY_DOWN);

  if (intakeUpButton)
    Robot::intake->move(KMaxMotorSpeed);
  else if (intakeDownButton)
    Robot::intake->move(-KMaxMotorSpeed);
  else
    Robot::intake->move(0);
}

bool IntakeControl::isFinished() {
  return true;
}

void IntakeControl::end() {
  // Code that runs when isFinished() returns true.
}

void IntakeControl::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
