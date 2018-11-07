#include "libIterativeRobot/subsystems/Base.h"
#include "libIterativeRobot/commands/ExampleCommand.h"

#include "libIterativeRobot/commands/DriveWithJoysticks.h"

Base::Base() {
  // Left side

  leftFrontBaseMotor = Motor::getMotor(leftFrontBaseMotorPort);
  leftBackBaseMotor = Motor::getMotor(leftBackBaseMotorPort);

  leftFrontBaseMotor->addFollower(leftBackBaseMotor);

  // Right side

  rightFrontBaseMotor = Motor::getMotor(rightFrontBaseMotorPort);
  rightBackBaseMotor = Motor::getMotor(rightBackBaseMotorPort);

  rightFrontBaseMotor->addFollower(rightBackBaseMotor);
}

void Base::toggleBase() {
  leftFrontBaseMotor->reverse();
  leftBackBaseMotor->reverse();
  rightFrontBaseMotor->reverse();
  rightBackBaseMotor->reverse();
}

void Base::toggleBaseSpeed() {
  baseSlow = !baseSlow;
}

void Base::moveBase(int leftSpeed, int rightSpeed) {
  double left = threshold(leftSpeed);
  double right = threshold(rightSpeed);
  left *= 2; // Change 100% from joystick to 200 rpm
  right *= 2;

  if (baseSlow) {
    left = (int)(slowSpeedMultiplier * left);
    right = (int)(slowSpeedMultiplier * right);
  }

  leftFrontBaseMotor->setSpeed(left);
  rightFrontBaseMotor->setSpeed(right);
}

void Base::moveBaseTo(int leftTarget, int rightTarget, int motorSpeed) {
  leftFrontBaseMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 150); // TODO: Move last argument to a variable
  leftBackBaseMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ?  motorSpeed : 150);

  rightFrontBaseMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 150);
  rightBackBaseMotor->getMotorObject()->move_relative(rightTarget, motorSpeed ? motorSpeed : 150);
}

bool Base::baseAtTarget() {
  return abs(leftFrontBaseMotor->getMotorObject()->get_target_position() - leftFrontBaseMotor->getMotorObject()->get_position()) <= 5; // Tune threshold and make a varaible
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new DriveWithJoysticks());
}
