#include "main.h"
#include "commands/DriveWithJoy.h"

Base* Base::instance = 0;

Base::Base() {
  // Get left base motors
  leftFrontBaseMotor = Motor::getMotor(frontLeftBasePort);
  leftRearBaseMotor = Motor::getMotor(backLeftBasePort);

  // Get right base motors
  rightFrontBaseMotor = Motor::getMotor(frontRightBasePort);
  rightRearBaseMotor = Motor::getMotor(backRightBasePort);

  // Reverse motors
  rightRearBaseMotor->reverse();
  rightFrontBaseMotor->reverse();

  // Set follower motors
  leftFrontBaseMotor->addFollower(leftRearBaseMotor);
  rightFrontBaseMotor->addFollower(rightRearBaseMotor);

}

void Base::initDefaultCommand() {
  setDefaultCommand(new DriveWithJoy());
}

/**
 * Move the base
 * @param left - speed of the left side
 * @param right - speed of the right side
 */
void Base::move(int left, int right) {
  left = threshold((int)left);
  right = threshold((int)right);

  //Left motors
  leftFrontBaseMotor->setSpeed(left);

  //Right motors
  rightFrontBaseMotor->setSpeed(right);
}

Base* Base::getInstance() {
    if (instance == 0) {
      instance = new Base();
    }

    return instance;
}
