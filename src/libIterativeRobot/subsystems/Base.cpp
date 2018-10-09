#include "libIterativeRobot/subsystems/Base.h"
#include "libIterativeRobot/commands/ExampleCommand.h"

#include "libIterativeRobot/commands/DriveWithJoysticks.h"

Base::Base() {
  leftFrontBaseMotor = Motor::getMotor(leftFrontBaseMotorPort);
  leftBackBaseMotor = Motor::getMotor(leftBackBaseMotorPort);

  // TODO: Use our motor's reverse() methods after initial testing

  rightFrontBaseMotor = Motor::getMotor(rightFrontBaseMotorPort);
  rightBackBaseMotor = Motor::getMotor(rightBackBaseMotorPort);
}

void Base::moveBase(int left, int right) {
  leftFrontBaseMotor->getMotorObject()->move_velocity(-left);
  leftBackBaseMotor->getMotorObject()->move_velocity(-left);

  rightFrontBaseMotor->getMotorObject()->move_velocity(right);
  rightBackBaseMotor->getMotorObject()->move_velocity(right);
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new DriveWithJoysticks());
}
