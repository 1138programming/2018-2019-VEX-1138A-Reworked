#include "libIterativeRobot/subsystems/Base.h"
#include "libIterativeRobot/commands/ExampleCommand.h"
#include "abstractBaseClasses/PIDController.h"

#include "libIterativeRobot/commands/DriveWithJoysticks.h"

Base::Base() {
  leftFrontBaseMotor = Motor::getMotor(leftFrontBaseMotorPort);
  leftBackBaseMotor = Motor::getMotor(leftBackBaseMotorPort);

  // TODO: Use our motor's reverse() methods after initial testing

  rightFrontBaseMotor = Motor::getMotor(rightFrontBaseMotorPort);
  rightBackBaseMotor = Motor::getMotor(rightBackBaseMotorPort);

  leftFrontBaseMotor->addFollower(leftBackBaseMotor);
  rightFrontBaseMotor->addFollower(rightBackBaseMotor);

  leftFrontBaseMotor->getMotorObject()->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rightFrontBaseMotor->getMotorObject()->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  leftBackBaseMotor->getMotorObject()->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  rightBackBaseMotor->getMotorObject()->set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

  leftController = new PIDController(leftFrontBaseMotor, 1, 0, 0);
  rightController = new PIDController(rightFrontBaseMotor, 1, 0, 0);

  baseGyro = new pros::ADIGyro(gyroPort);
}

void Base::toggleBase() {
  baseReversed = !baseReversed;
}

void Base::toggleBaseSpeed() {
  baseSlow = !baseSlow;
}

void Base::move(int left, int right) {
  leftFrontBaseMotor->setSpeed(left);
  rightFrontBaseMotor->setSpeed(right);
}

void Base::moveBase(int leftSpeed, int rightSpeed) {
  double left = threshold(leftSpeed);
  double right = threshold(rightSpeed);
  left *= 2;
  right *= 2;

  if (baseReversed) {
    int tmp;
    tmp = left;
    left = -right;
    right = -tmp;
  }

  if (baseSlow) {
    left = slowSpeedMultiplier * left;
    right = slowSpeedMultiplier * right;
  }

  left = (int) left;
  right = (int) right;

  leftFrontBaseMotor->getMotorObject()->move_velocity(-left);
  leftBackBaseMotor->getMotorObject()->move_velocity(-left);

  rightFrontBaseMotor->getMotorObject()->move_velocity(right);
  rightBackBaseMotor->getMotorObject()->move_velocity(right);
}

void Base::moveBaseTo(int leftTarget, int rightTarget, int motorSpeed) {
  leftFrontBaseMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 150); // TODO: Move last argument to a variable
  leftBackBaseMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ?  motorSpeed : 150);

  rightFrontBaseMotor->getMotorObject()->move_relative(-rightTarget, motorSpeed ? motorSpeed : 150);
  rightBackBaseMotor->getMotorObject()->move_relative(-rightTarget, motorSpeed ? motorSpeed : 150);
}

double Base::getLeftVelocity() {
  return leftFrontBaseMotor->getMotorObject()->get_actual_velocity();
}

double Base::getRightVelocity() {
  return rightFrontBaseMotor->getMotorObject()->get_actual_velocity();
}

void Base::setVoltageLimit(int mV) {
  leftFrontBaseMotor->getMotorObject()->set_voltage_limit(mV);
  leftBackBaseMotor->getMotorObject()->set_voltage_limit(mV);

  rightFrontBaseMotor->getMotorObject()->set_voltage_limit(mV);
  rightBackBaseMotor->getMotorObject()->set_voltage_limit(mV);
}

bool Base::baseAtTarget() {
  return abs(leftFrontBaseMotor->getMotorObject()->get_target_position() - leftFrontBaseMotor->getMotorObject()->get_position()) <= 3; // Tune threshold and make a varaible
}

double Base::getGyroValue() {
  return baseGyro->get_value();
}

void Base::resetGyro() {
  baseGyro->reset();
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new DriveWithJoysticks());
}

void Base::setSetpoint(int leftSetpoint, int rightSetpoint) {
  leftController->setSetpoint(leftSetpoint);
  rightController->setSetpoint(rightSetpoint);
}

void Base::setSetpointRelative(int leftSetpoint, int rightSetpoint) {
  leftController->setSetpointRelative(leftSetpoint);
  rightController->setSetpointRelative(rightSetpoint);
}

int Base::getSetpointLeft() {
  return leftController->getSetpoint();
}

int Base::getSetpointRight() {
  return rightController->getSetpoint();
}

int Base::getOutputLeft() {
  return leftController->getOutput();
  //return leftFrontBaseMotor->getSlewedSpeed();
}

int Base::getOutputRight() {
  return rightController->getOutput();
  //return rightFrontBaseMotor->getSlewedSpeed();
}

bool Base::atSetpoint() {
  return leftController->atSetpoint() && rightController->atSetpoint();
}

void Base::enablePID() {
  leftController->enabled = true;
  rightController->enabled = true;
}

void Base::disablePID() {
  leftController->enabled = false;
  rightController->enabled = false;
}

void Base::setMaxPIDSpeed(int maxSpeed) {
  leftController->setMaxPIDSpeed(maxSpeed);
  rightController->setMaxPIDSpeed(maxSpeed);
}

std::int32_t Base::getLeftEncoder() {
  return leftFrontBaseMotor->getEncoderValue();
}

std::int32_t Base::getRightEncoder() {
  return rightFrontBaseMotor->getEncoderValue();
}
