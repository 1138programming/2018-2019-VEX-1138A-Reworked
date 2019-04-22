#include "libIterativeRobot/subsystems/Base.h"

#include "libIterativeRobot/commands/BaseCommands/DriveWithJoysticks.h"

Base::Base() {
  leftFrontBaseMotor = Motor::getMotor(leftFrontBaseMotorPort, baseMotorGearset);
  leftBackBaseMotor = Motor::getMotor(leftBackBaseMotorPort, baseMotorGearset);
  rightFrontBaseMotor = Motor::getMotor(rightFrontBaseMotorPort, baseMotorGearset);
  rightBackBaseMotor = Motor::getMotor(rightBackBaseMotorPort, baseMotorGearset);

  rightFrontBaseMotor->reverse();
  rightBackBaseMotor->reverse();

  leftFrontBaseMotor->addFollower(leftBackBaseMotor);
  rightFrontBaseMotor->addFollower(rightBackBaseMotor);

  leftPID = new PIDController(leftFrontBaseMotor, 0.15, 0, 0);
  rightPID = new PIDController(rightFrontBaseMotor, 0.15, 0, 0);

  leftPID->setOutputRange(-60, 60);
  rightPID->setOutputRange(-60, 60);

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

void Base::initLinearMovement(int target, bool absolute) {
  if (absolute) {
    leftPID->setSetpoint(target);
    rightPID->setSetpoint(target);
  } else {
    leftPID->setSetpointRelative(target);
    rightPID->setSetpointRelative(target);
  }
  leftPID->init();
  rightPID->init();
  leftPID->enabled = true;
  rightPID->enabled = true;
  // if (absolute) {
  //   velPID->setSetpoint(target);
  // } else {
  //   velPID->setSetpointRelative(target);
  // }
  //lastTime = pros::millis();
  //lastPos = getRightEncoderValue();
}

//void Base::updateLinearMovement() {
  //pros::delay(5);

  //int deltaTime = pros::millis() - lastTime;
  //double deltaPos = getRightEncoderValue() - lastPos;

  //printf("Delta time is %d\n", deltaTime);
  //printf("Delta pos is %f\n", deltaPos);
  //int vel = (int)(1000 * deltaPos / deltaTime);
  //printf("Velocity is %d\n", vel);

  // velPID->setSensorValue(vel);
  // velPID->loop();
  // int output = velPID->getOutput();
  // moveBase(output, output);

  //moveBase(60, 60);

  //lastTime = pros::millis();
  //lastPos = getRightEncoderValue();

  //basePIDController->setSensorValue((int)getRightEncoderValue());
  //printf("Enc pos: %d\n", (int)getRightEncoderValue());
  //printf("Target is %d\n", basePIDController->getSetpoint());
  //basePIDController->loop();
  //int output = reverseThreshold(-basePIDController->getOutput());
  //int output = basePIDController->getOutput();
  //printf("PID output is %d\n", output);
  //int gyroCorrection = baseGyro->get_value() * 0.11;
  //moveBase((int)(output + gyroCorrection), (int)(output - gyroCorrection));
  //moveBase(output, output);
//}

// bool Base::baseAtTarget() {
//   return abs(leftFrontBaseMotor->getMotorObject()->get_target_position() - leftFrontBaseMotor->getMotorObject()->get_position()) <= 3; // Tune threshold and make a varaible
// }

bool Base::baseAtLinearTarget() {
  return leftPID->atSetpoint() && rightPID->atSetpoint();
}

void Base::stopLinearMovement() {
  leftPID->stop();
  rightPID->stop();
  leftPID->enabled = false;
  rightPID->enabled = false;
}

double Base::getGyroValue() {
  return baseGyro->get_value();///(3.3 * (wheelArcLength / 2 * M_PI) * 20) + (baseGyro->get_value() * 0.8);
}

double Base::getLeftEncoderValue() {
  //return leftBackBaseMotor->getEncoderValue();
  return leftFrontBaseMotor->getEncoderValue();
}

double Base::getRightEncoderValue() {
  return rightFrontBaseMotor->getEncoderValue();
  //return rightBackBaseMotor->getEncoderValue();
}

void Base::resetEncoders() {
  leftFrontBaseMotor->resetEncoder();
  rightFrontBaseMotor->resetEncoder();
}

void Base::resetGyro() {
  baseGyro->reset();
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new DriveWithJoysticks());
}
