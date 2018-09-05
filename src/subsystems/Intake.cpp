#include "main.h"
#include "commands/IntakeControl.h"

Intake* Intake::instance = 0;

Intake::Intake() {
  intakeMotor = Motor::getMotor(intakePort);
}

void Intake::initDefaultCommand() {
  setDefaultCommand(new IntakeControl());
}

void Intake::move(int speed) {
  intakeMotor->setSpeed(speed);
}

Intake* Intake::getInstance() {
  if (instance == 0) {
    instance = new Intake();
  }

  return instance;
}
