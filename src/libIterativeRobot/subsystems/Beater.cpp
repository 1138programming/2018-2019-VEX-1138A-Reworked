#include "libIterativeRobot/subsystems/Beater.h"
#include "libIterativeRobot/commands/BeaterIdle.h"

Beater::Beater() {
  beaterMotor = Motor::getMotor(beaterPort);
  beaterMotor->reverse();
  // Slaving will be tested after initial test
}

void Beater::runBeater(int velocity) {
  beaterMotor->setSpeed(-velocity);
}

void Beater::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new BeaterIdle());
}
