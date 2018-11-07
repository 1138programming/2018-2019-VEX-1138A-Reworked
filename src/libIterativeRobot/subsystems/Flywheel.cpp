#include "libIterativeRobot/subsystems/Flywheel.h"
#include "libIterativeRobot/commands/FlywheelMonitor.h"

Flywheel::Flywheel() {
  flywheelMotor = Motor::getMotor(flywheelMotorPort);
  flywheelMotor->reverse();
}

void Flywheel::setFlywheel(int velocity) {
  flywheelMotor->setSpeed(velocity);
}

double Flywheel::getFlywheelTemperature() {
  return flywheelMotor->getMotorObject()->get_temperature();
}

double Flywheel::getFlywheelVelocity() {
  return flywheelMotor->getMotorObject()->get_actual_velocity(); // Need to check units
}

void Flywheel::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new FlywheelMonitor());
}
