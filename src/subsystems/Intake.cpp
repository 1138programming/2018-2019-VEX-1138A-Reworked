#include "main.h"

Intake* Intake::instance = 0;

Intake::Intake() {
  intakeMotor = Motor::getMotor(intakePort);

  intakeEncoder = encoderInit(intakeEncoderTopPort, intakeEncoderBottomPort, true);
  resetEncoder();

  controller = new PIDController(intakeMotor, 0.9, 0.01, 0.0);
  controller->setThreshold(20);
}

void Intake::move(int speed) {
  intakeMotor->setSpeed(speed);
}

void Intake::setSetpoint(int setpoint) {
  controller->setSetpoint(setpoint);
}

void Intake::lock() {
  controller->setSetpoint(getEncoderValue());
}

int Intake::getSetpoint() {
  return controller->getSetpoint();
}

void Intake::loop() {
  controller->sensorValue(getEncoderValue());
  controller->loop();
}

bool Intake::atSetpoint() {
  return controller->atSetpoint();
}

int Intake::getEncoderValue() {
  return encoderGet(intakeEncoder);
}

void Intake::resetEncoder() {
  encoderReset(intakeEncoder);
}

Intake* Intake::getInstance() {
  if (instance == 0) {
    instance = new Intake();
  }

  return instance;
}
