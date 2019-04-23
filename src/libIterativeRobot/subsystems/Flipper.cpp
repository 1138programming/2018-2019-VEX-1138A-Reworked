#include "libIterativeRobot/subsystems/Flipper.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperIdle.h"

Flipper::Flipper() {
  flipperMotor = Motor::getMotor(flipperPort, flipperGearset);

  flipperControl = new PIDController(flipperMotor, 0.4, 0.001, 0);

  bottomLimit = 550;
}

void Flipper::runFlipper(int velocity) {
  //flipperMotor->getMotorObject()->move_velocity(velocity);
  flipperMotor->setSpeed(velocity);
}

void Flipper::setSetpoint(int setpoint) {
  flipperControl->setSetpoint(setpoint);
}

void Flipper::setSetpointRelative(int setpoint) {
  flipperControl->setSetpointRelative(setpoint);
}

bool Flipper::atTarget() {
  return flipperControl->atSetpoint();
}

int Flipper::getEncoderValue() {
  return (int)flipperMotor->getEncoderValue();
}

void Flipper::enable() {
  flipperControl->enable();
}

void Flipper::disable() {
  flipperControl->disable();
}

void Flipper::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new FlipperIdle());
}
