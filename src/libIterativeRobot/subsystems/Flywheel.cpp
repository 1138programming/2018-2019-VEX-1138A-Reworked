#include "libIterativeRobot/subsystems/Flywheel.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelMonitor.h"
// TODO: Make a flywheel monitoring command

Flywheel::Flywheel() {
  flywheelMotor = Motor::getMotor(flywheelMotorPort, flywheelGearset);
  flywheelMotor->enableSlewing(1);
  flywheelMotor->getMotorObject()->set_gearing(pros::E_MOTOR_GEARSET_06);
}

void Flywheel::setFlywheel(int velocity) {
  //printf("Setting flywheel to %d\n", velocity * 20);
  //flywheelMotor->getMotorObject()->move_voltage(velocity * 20);
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
