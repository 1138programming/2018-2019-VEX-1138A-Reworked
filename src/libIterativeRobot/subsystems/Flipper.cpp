#include "libIterativeRobot/subsystems/Flipper.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperIdle.h"

Flipper::Flipper() {
  flipperMotor = Motor::getMotor(flipperPort);
  // Slaving will be tested after initial test
}

void Flipper::runFlipper(int velocity) {
  flipperMotor->getMotorObject()->move_velocity(velocity);
}

void Flipper::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new FlipperIdle());
}
