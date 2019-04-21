#include "libIterativeRobot/subsystems/Base.h"

#include "libIterativeRobot/commands/BaseCommands/DriveWithJoysticks.h"

Base::Base() {
  basePIDController = new PIDController(0.05, 0, 0.00125);
  leftFrontBaseMotor = Motor::getMotor(leftFrontBaseMotorPort, baseMotorGearset);
  leftBackBaseMotor = Motor::getMotor(leftBackBaseMotorPort, baseMotorGearset);
  rightFrontBaseMotor = Motor::getMotor(rightFrontBaseMotorPort, baseMotorGearset);
  rightBackBaseMotor = Motor::getMotor(rightBackBaseMotorPort, baseMotorGearset);

  leftFrontBaseMotor->addFollower(leftBackBaseMotor);
  rightFrontBaseMotor->addFollower(rightBackBaseMotor);

  baseGyro = new pros::ADIGyro(gyroPort);
  pros::c::adi_gyro_init(gyroPort, 1);
  pros::c::delay(1300);
  baseGyro->reset();
}

void Base::setBaseMode(pros::motor_brake_mode_e motorMode) {
  leftFrontBaseMotor->getMotorObject()->set_brake_mode(motorMode);
  rightFrontBaseMotor->getMotorObject()->set_brake_mode(motorMode);
  leftBackBaseMotor->getMotorObject()->set_brake_mode(motorMode);
  rightBackBaseMotor->getMotorObject()->set_brake_mode(motorMode);
}

void Base::moveBase(int leftSpeed, int rightSpeed) {
  leftFrontBaseMotor->setSpeed(leftSpeed);
  rightFrontBaseMotor->setSpeed(rightSpeed);
}

/*void Base::moveBaseTo(int leftTarget, int rightTarget, int motorSpeed) {
  leftFrontBaseMotor->getMotorObject()->tare_position();
  leftBackBaseMotor->getMotorObject()->tare_position();
  rightFrontBaseMotor->getMotorObject()->tare_position();
  rightBackBaseMotor->getMotorObject()->tare_position();
  leftFrontBaseMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ? motorSpeed : 150); // TODO: Move last argument to a variable
  leftBackBaseMotor->getMotorObject()->move_relative(leftTarget, motorSpeed ?  motorSpeed : 150);

  rightFrontBaseMotor->getMotorObject()->move_relative(-rightTarget, motorSpeed ? motorSpeed : 150);
  rightBackBaseMotor->getMotorObject()->move_relative(-rightTarget, motorSpeed ? motorSpeed : 150);
}*/

/*void Base::moveBaseForward(int target, int motorSpeed) {
  leftFrontBaseMotor->getMotorObject()->tare_position();
  leftBackBaseMotor->getMotorObject()->tare_position();
  rightFrontBaseMotor->getMotorObject()->tare_position();
  rightBackBaseMotor->getMotorObject()->tare_position();

  basePIDController->setSetpoint(target);
  basePIDController->setMaxPIDSpeed(motorSpeed ? motorSpeed : 150);
  basePIDController->setSensorValue(0);
  baseGyro->reset();
}*/

void Base::setLinearTarget(int target, bool absolute) {
  if (absolute) {
    basePIDController->setSetpoint(target);
  } else {
    basePIDController->setSetpointRelative(target);
  }
}

void Base::updateLinearMovement() {
  basePIDController->setSensorValue(-rightFrontBaseMotor->getMotorObject()->get_position());
  printf("Enc pos: %d\n", rightFrontBaseMotor->getMotorObject()->get_position());
  printf("Target is %d\n", basePIDController->getSetpoint());
  basePIDController->loop();
  int output = reverseThreshold(-basePIDController->getOutput());
  int gyroCorrection = baseGyro->get_value() * 0.11;
  moveBase(output + gyroCorrection, output - gyroCorrection);
}

// bool Base::baseAtTarget() {
//   return abs(leftFrontBaseMotor->getMotorObject()->get_target_position() - leftFrontBaseMotor->getMotorObject()->get_position()) <= 3; // Tune threshold and make a varaible
// }

bool Base::baseAtLinearTarget() {
  return basePIDController->atSetpoint();
}

double Base::getGyroValue() {
  return baseGyro->get_value();///(3.3 * (wheelArcLength / 2 * M_PI) * 20) + (baseGyro->get_value() * 0.8);
}

double Base::getLeftEncoderValue() {
  return leftFrontBaseMotor->getEncoderValue();
}

double Base::getRightEncoderValue() {
  return rightFrontBaseMotor->getEncoderValue();
}

void Base::resetGyro() {
  baseGyro->reset();
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new DriveWithJoysticks());
}
