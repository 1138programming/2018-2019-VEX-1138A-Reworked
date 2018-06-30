#include "main.h"

Puncher* Puncher::instance = 0;

Puncher::Puncher() {
  puncherMotor = Motor::getMotor(puncherPort);

  puncherEncoder = encoderInit(puncherEncoderTopPort, puncherEncoderBottomPort, true);
  resetEncoder();

  controller = new PIDController(puncherMotor, 0.9, 0.01, 0.0);
  controller->setSensorEncoder(puncherEncoder);
  controller->setThreshold(20);
}

void Puncher::move(int speed) {
  puncherMotor->setSpeed(speed);
}

void Puncher::setSetpoint(int setpoint) {
  controller->setSetpoint(setpoint);
}

void Puncher::lock() {
  controller->setSetpoint(getEncoderValue());
}

int Puncher::getSetpoint() {
  return controller->getSetpoint();
}

void Puncher::loop() {
  controller->loop();
}

bool Puncher::atSetpoint() {
  return controller->atSetpoint();
}

int Puncher::getEncoderValue() {
  return encoderGet(puncherEncoder);
}

void Puncher::resetEncoder() {
  encoderReset(puncherEncoder);
}

Puncher* Puncher::getInstance() {
  if (instance == 0) {
    instance = new Puncher();
  }

  return instance;
}
