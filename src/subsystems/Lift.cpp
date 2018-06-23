#include "main.h"

Lift* Lift::instance = 0;

Lift::Lift() {
  leftLiftMotor = Motor::getMotor(leftLiftPort);
  rightLiftMotor = Motor::getMotor(rightLiftPort);

  leftLiftMotor->addFollower(rightLiftMotor);

  liftEncoder = encoderInit(liftEncoderTopPort, liftEncoderBottomPort, true);
  resetEncoder();

  controller = new PIDController(leftLiftMotor, 0.9, 0.01, 0.0);
  controller->setThreshold(20);
}

void Lift::move(int speed) {
  leftLiftMotor->setSpeed(speed);
}

void Lift::setSetpoint(int setpoint) {
  controller->setSetpoint(setpoint);
}

void Lift::lock() {
  controller->setSetpoint(getEncoderValue());
}

int Lift::getSetpoint() {
  return controller->getSetpoint();
}

void Lift::loop() {
  controller->sensorValue(getEncoderValue());
  controller->loop();
}

bool Lift::atSetpoint() {
  return controller->atSetpoint();
}

int Lift::getEncoderValue() {
  return encoderGet(liftEncoder);
}

void Lift::resetEncoder() {
  encoderReset(liftEncoder);
}

Lift* Lift::getInstance() {
  if (instance == 0) {
    instance = new Lift();
  }

  return instance;
}
