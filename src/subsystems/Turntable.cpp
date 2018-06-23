#include "main.h"

Turntable* Turntable::instance = 0;

Turntable::Turntable() {
  turntableMotor = Motor::getMotor(turntablePort);

  turntableEncoder = encoderInit(turntableEncoderTopPort, turntableEncoderBottomPort, true);
  resetEncoder();

  controller = new PIDController(turntableMotor, 0.9, 0.01, 0.0);
  controller->setThreshold(20);
}

void Turntable::move(int speed) {
  turntableMotor->setSpeed(speed);
}

void Turntable::setSetpoint(int setpoint) {
  controller->setSetpoint(setpoint);
}

void Turntable::lock() {
  controller->setSetpoint(getEncoderValue());
}

int Turntable::getSetpoint() {
  return controller->getSetpoint();
}

void Turntable::loop() {
  controller->sensorValue(getEncoderValue());
  controller->loop();
}

bool Turntable::atSetpoint() {
  return controller->atSetpoint();
}

int Turntable::getEncoderValue() {
  return encoderGet(turntableEncoder);
}

void Turntable::resetEncoder() {
  encoderReset(turntableEncoder);
}

Turntable* Turntable::getInstance() {
  if (instance == 0) {
    instance = new Turntable();
  }

  return instance;
}
