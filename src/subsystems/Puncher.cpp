#include "main.h"
#include "commands/PuncherControl.h"

Puncher* Puncher::instance = 0;

Puncher::Puncher() {
  puncherMotor = Motor::getMotor(puncherPort);
}

void Puncher::initDefaultCommand() {
  setDefaultCommand(new PuncherControl());
}

void Puncher::move(int speed) {
  puncherMotor->setSpeed(speed);
}

Puncher* Puncher::getInstance() {
  if (instance == 0) {
    instance = new Puncher();
  }

  return instance;
}
