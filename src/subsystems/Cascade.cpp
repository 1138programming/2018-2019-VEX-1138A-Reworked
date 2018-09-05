#include "main.h"
#include "commands/CascadeControl.h"

Cascade* Cascade::instance = 0;

Cascade::Cascade() {
  cascadeMotorOne = Motor::getMotor(CascadeMotorOnePort);
  cascadeMotorTwo = Motor::getMotor(CascadeMotorTwoPort);

  cascadeMotorOne->reverse();
  cascadeMotorTwo->reverse();

  cascadeMotorOne->addFollower(cascadeMotorTwo);
}

void Cascade::initDefaultCommand() {
  setDefaultCommand(new CascadeControl());
}

void Cascade::move(int speed) {
  cascadeMotorOne->setSpeed(speed);
}

Cascade* Cascade::getInstance() {
  if (instance == 0) {
    instance = new Cascade();
  }

  return instance;
}
