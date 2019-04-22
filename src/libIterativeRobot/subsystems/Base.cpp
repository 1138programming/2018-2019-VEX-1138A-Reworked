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

  baseGyro = new pros::ADIGyro(gyroPort);
  pros::c::adi_gyro_init(gyroPort, 1);
  pros::c::delay(1300);
  baseGyro->reset();

  gyroPID = new PIDController(0.1, 0, 0);
  gyroPID->setOutputRange(-200, 200);

  leftPosPID = new PIDController(0.1, 0, 0);
  rightPosPID = new PIDController(0.1, 0, 0);
  leftPosPID->setOutputRange(-200, 200);
  rightPosPID->setOutputRange(-200, 200);

  leftVelPID = new PIDController(0.05, 0, 0);
  rightVelPID = new PIDController(0.05, 0, 0);
  leftVelPID->setOutputRange(-60, 60);
  rightVelPID->setOutputRange(-60, 60);
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

void Base::initLinearMovement(int leftTarget, int rightTarget, bool absolute) {
  if (absolute) {
    leftPosPID->setSetpoint(leftTarget);
    rightPosPID->setSetpoint(rightTarget);
  } else {
    leftPosPID->setSetpointRelative(leftTarget);
    rightPosPID->setSetpointRelative(rightTarget);
  }
  //leftPosPID->init();
  //rightPosPID->init();
  leftPosPID->enable();
  rightPosPID->enable();
  leftVelPID->enable();
  rightVelPID->enable();

  // Loop the position PIDs once so that they have a useful output to give to the velocity PIDs
  leftPosPID->loop();
  rightPosPID->loop();
  // if (absolute) {
  //   velPID->setSetpoint(target);
  // } else {
  //   velPID->setSetpointRelative(target);
  // }
  //lastTime = pros::millis();
  //lastPos = getRightEncoderValue();
}

void Base::updateLinearMovement() {
  pros::delay(5);

  // Passes encoder values to the position PIDs
  leftPosPID->setSensorValue((int)getLeftEncoderValue());
  rightPosPID->setSensorValue((int)getRightEncoderValue());

  // Passes the position PIDs' outputs to the velocity PIDs as their setpoints
  leftVelPID->setSetpoint(leftPosPID->getOutput());
  rightVelPID->setSetpoint(rightPosPID->getOutput());

  // Passes velocitie values to the velocity PIDs
  leftVelPID->setSensorValue((int)leftFrontBaseMotor->getMotorObject()->get_actual_velocity());
  rightVelPID->setSensorValue((int)rightFrontBaseMotor->getMotorObject()->get_actual_velocity());

  // Moves the base using the velocity PIDs' outputs
  moveBase(leftVelPID->getOutput(), rightVelPID->getOutput());
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
}

// bool Base::baseAtTarget() {
//   return abs(leftFrontBaseMotor->getMotorObject()->get_target_position() - leftFrontBaseMotor->getMotorObject()->get_position()) <= 3; // Tune threshold and make a varaible
// }

bool Base::baseAtLinearTarget() {
  return leftPosPID->atSetpoint() && rightPosPID->atSetpoint();
}

void Base::stopLinearMovement() {
  //leftPosPID->stop();
  //rightPosPID->stop();
  leftPosPID->disable();
  rightPosPID->disable();
  leftVelPID->disable();
  rightVelPID->disable();
}

void Base::initTurnWithGyro(int target, bool absolute) {
  if (absolute) {
    gyroPID->setSetpoint(target);
  } else {
    gyroPID->setSetpointRelative(target);
  }

  gyroPID->enable();
  leftVelPID->enable();
  rightVelPID->enable();

  gyroPID->loop();
}

void Base::updateTurnWithGyro() {
  pros::delay(5);

  // Passes the gyro value to the gyro PID
  gyroPID->setSensorValue((int)getGyroValue());

  // Passes the position PIDs' outputs to the velocity PIDs as their setpoints
  leftVelPID->setSetpoint(gyroPID->getOutput());
  rightVelPID->setSetpoint(gyroPID->getOutput());

  // Passes velocitie values to the velocity PIDs
  leftVelPID->setSensorValue((int)leftFrontBaseMotor->getMotorObject()->get_actual_velocity());
  rightVelPID->setSensorValue((int)rightFrontBaseMotor->getMotorObject()->get_actual_velocity());

  // Moves the base using the velocity PIDs' outputs
  moveBase(leftVelPID->getOutput(), rightVelPID->getOutput());
}

bool Base::atTurnTarget() {
  return gyroPID->atSetpoint();
}

void Base::stopTurnWithGyro() {
  gyroPID->disable();
  leftVelPID->disable();
  rightVelPID->disable();
}

double Base::getLeftEncoderValue() {
  //return leftBackBaseMotor->getEncoderValue();
  return leftFrontBaseMotor->getEncoderValue();
}

double Base::getRightEncoderValue() {
  return rightFrontBaseMotor->getEncoderValue();
  //return rightBackBaseMotor->getEncoderValue();
}

double Base::getGyroValue() {
  return baseGyro->get_value();///(3.3 * (wheelArcLength / 2 * M_PI) * 20) + (baseGyro->get_value() * 0.8);
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
