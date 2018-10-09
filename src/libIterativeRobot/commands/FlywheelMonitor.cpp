#include "libIterativeRobot/commands/FlywheelMonitor.h"
#include "libIterativeRobot/Robot.h"

FlywheelMonitor::FlywheelMonitor() {
  requires(Robot::flywheel);
}

bool FlywheelMonitor::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelMonitor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlywheelMonitor::execute() {
  // Code that runs when this command is scheduled to run
  Robot::mainController->set_text(0, 0, "Flywheel");
  Robot::mainController->print(1, 0, "RPM: %f", Robot::flywheel->getFlywheelVelocity());
  Robot::mainController->print(2, 0, "Temp: %f", Robot::flywheel->getFlywheelTemperature());

  Robot::flywheel->setFlywheel(0);
}

bool FlywheelMonitor::isFinished() {
  return true; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelMonitor::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelMonitor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
