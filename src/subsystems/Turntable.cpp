#include "main.h"
#include "commands/TurntableControl.h"

Turntable* Turntable::instance = 0;

Turntable::Turntable() {
  turntableMotor = Motor::getMotor(clawPort);
}

void Turntable::initDefaultCommand() {
  setDefaultCommand(new TurntableControl());
}

void Turntable::move(int speed) {
  turntableMotor->setSpeed(speed);
}

Turntable* Turntable::getInstance() {
  if (instance == 0) {
    instance = new Turntable();
  }

  return instance;
}
