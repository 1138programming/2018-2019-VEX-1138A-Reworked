#include "libIterativeRobot/commands/BaseCommands/ToggleBrake.h"

#include "libIterativeRobot/Robot.h"

ToggleBrake::ToggleBrake(bool brake) {
  requires(Robot::robotBase);
  this->brake = brake;
}

bool ToggleBrake::canRun() {
  //printf("ToggleBrake(%d);\n", degrees);
  return true; // This is the default value anyways, so this method can be removed
}

void ToggleBrake::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  if (brake) {
    Robot::robotBase->setBaseMode(pros::E_MOTOR_BRAKE_HOLD);
  } else {
    Robot::robotBase->setBaseMode(pros::E_MOTOR_BRAKE_COAST);
  }
}

void ToggleBrake::execute() {
  // Code that runs when this command is scheduled to run
}

bool ToggleBrake::isFinished() {
  return true;
}

void ToggleBrake::end() {
  // Code that runs when isFinished() returns true.
}

void ToggleBrake::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
