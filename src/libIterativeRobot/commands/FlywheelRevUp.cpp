#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/Robot.h"

FlywheelRevUp::FlywheelRevUp() {
  priority = 45; // Less priority, so that we can be interrupted when we actually want to shoot
  requires(Robot::flywheel);
}

bool FlywheelRevUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelRevUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::flywheel->setFlywheel(200);
}

void FlywheelRevUp::execute() {
  // Code that runs when this command is scheduled to run
  Robot::mainController->set_text(0, 0, "Flywheel");
  Robot::mainController->print(1, 0, "RPM: %f", Robot::flywheel->getFlywheelVelocity());
  Robot::mainController->print(2, 0, "Temp: %f", Robot::flywheel->getFlywheelTemperature());
}

bool FlywheelRevUp::isFinished() {
  return false; // This is the default va  lue anyways, so this method can be removed
}

void FlywheelRevUp::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelRevUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
