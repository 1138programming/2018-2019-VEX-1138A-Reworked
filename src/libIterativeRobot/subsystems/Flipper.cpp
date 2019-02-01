#include "libIterativeRobot/subsystems/Flipper.h"
#include "libIterativeRobot/commands/FlipperIdle.h"

Flipper::Flipper() {
  flipperMotor = Motor::getMotor(flipperPort);
  // Slaving will be tested after initial test
}

void Flipper::runFlipperForward(int velocity) {
  flipperMotor->getMotorObject()->move_voltage(velocity * 18);
}
void Flipper::runFlipperBackward(int velocity) {
  flipperMotor->getMotorObject()->move_velocity(velocity);
}
void Flipper::runFlipperDriver(int velocity) {
  flipperMotor->getMotorObject()->move_velocity(velocity);
}

void Flipper::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new FlipperIdle());
}
