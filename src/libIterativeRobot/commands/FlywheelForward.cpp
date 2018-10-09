#include "libIterativeRobot/commands/FlywheelForward.h"
#include "libIterativeRobot/Robot.h"

FlywheelForward::FlywheelForward() {
  requires(Robot::flywheel);
}

bool FlywheelForward::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelForward::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlywheelForward::execute() {
  // Code that runs when this command is scheduled to run
  Robot::mainController->set_text(0, 0, "Flywheel");
  Robot::mainController->print(1, 0, "RPM: %f", Robot::flywheel->getFlywheelVelocity());
  Robot::mainController->print(2, 0, "Temp: %f", Robot::flywheel->getFlywheelTemperature());

  Robot::flywheel->setFlywheel(200);
}

bool FlywheelForward::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelForward::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelForward::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
