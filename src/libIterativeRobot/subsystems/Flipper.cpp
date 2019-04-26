#include "libIterativeRobot/subsystems/Flipper.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperIdle.h"

Flipper::Flipper() {
  flipperMotor = Motor::getMotor(flipperPort, flipperGearset);

  flipperControl = new PIDController(flipperMotor, 0.4, 0, 0);
  flipperControl->setThreshold(30);

  bottomLimit = 550;
  bottomHuntRange = 200;
}

void Flipper::runFlipper(int velocity) {
  //flipperMotor->getMotorObject()->move_velocity(velocity);

  int enc = getEncoderValue();
  int maxSpeed;

  if (enc > (bottomLimit - bottomHuntRange)) {
    maxSpeed = (int)(127 * ((0.75 * ((bottomLimit - enc) / (bottomLimit - bottomHuntRange))) + 0.25));
    if (velocity > maxSpeed)
      velocity = maxSpeed;
  }

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

PIDController* Flipper::getPID() {
  return flipperControl;
}

void Flipper::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new FlipperIdle());
}
