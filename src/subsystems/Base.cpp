#include "main.h"
#include "commands/DriveWithJoy.h"

Base* Base::instance = 0;

Base::Base() {
  // Get left base motors
  leftFrontBaseMotor = Motor::getMotor(leftFrontBasePort);
  leftMiddleBaseMotor = Motor::getMotor(leftMiddleBasePort);
  leftRearBaseMotor = Motor::getMotor(leftRearBasePort);

  // Get right base motors
  rightFrontBaseMotor = Motor::getMotor(rightFrontBasePort);
  rightMiddleBaseMotor = Motor::getMotor(rightMiddleBasePort);
  rightRearBaseMotor = Motor::getMotor(rightRearBasePort);

  // Reverse motors
  leftRearBaseMotor->reverse();
  rightFrontBaseMotor->reverse();
  rightMiddleBaseMotor->reverse();
  rightRearBaseMotor->reverse();

  // Set follower motors
  leftFrontBaseMotor->addFollower(leftMiddleBaseMotor);
  leftFrontBaseMotor->addFollower(leftRearBaseMotor);
  rightFrontBaseMotor->addFollower(rightMiddleBaseMotor);
  rightFrontBaseMotor->addFollower(rightRearBaseMotor);

  // Set up the base encoders
  baseLeftEncoder = encoderInit(baseLeftEncoderTopPort, baseLeftEncoderBottomPort, true);
  baseRightEncoder = encoderInit(baseRightEncoderTopPort, baseRightEncoderBottomPort, true);
  resetEncoders();

  // Set up the PID controllers
  leftController = new PIDController(leftFrontBaseMotor, 0.6, 0.0, 0.0);
  rightController = new PIDController(rightFrontBaseMotor, 0.6, 0.0, 0.0);

  leftController->setSensorEncoder(baseLeftEncoder);
  rightController->setSensorEncoder(baseRightEncoder);

  leftController->setThreshold(35);
  rightController->setThreshold(35);

  gyro = gyroInit(gyroPort, 196);
  //ultrasonic = ultrasonicInit(ultrasonicEcho, ultrasonicPing);

  encoderReference = 0;
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
  left = threshold((int)left * this->multiplier);
  right = threshold((int)right * this->multiplier);

  //Left motors
  leftFrontBaseMotor->setSpeed(left);
  //leftMiddleBaseMotor->setSpeed(left);
  //leftRearBaseMotor->setSpeed(left);

  //Right motors
  rightFrontBaseMotor->setSpeed(right);
  //rightMiddleBaseMotor->setSpeed(right);
  //rightRearBaseMotor->setSpeed(right);
}

bool Base::moveTo(int target, int logValue, int threshold) {
  setReference();

  // Set speed. Speed should decrease as the base gets closer to the target value
  int averageEncoderValue = (int)((getRightEncoderValue() + getLeftEncoderValue()) / 2);
  int speed = (int)(floor((KMaxMotorSpeed * log(abs((encoderReference + target) - averageEncoderValue) + 1)) / log(logValue + 1)));
  speed *= (encoderReference + target) > averageEncoderValue ? 1 : -1;

  // Move base by speed
  move(speed, speed);

  return inRange(target, target - threshold, target + threshold);
}

bool Base::turnTo(int target, int logValue, int threshold, int direction) {
  int gyroValue = getGyro();
  gyroValue = (int)(gyroValue - (floor(gyroValue / 360) * 360));
  //printf("Gyro value is %d and target is %d\n", gyroValue, target);

  int rightAngle = target > gyroValue ? target - gyroValue : (360 - gyroValue) + target;
  int leftAngle = target > gyroValue ? (360 - gyroValue) + target : gyroValue - target;

  int speed = (int)(floor((KMaxMotorSpeed * log(abs(target - gyroValue) + 1)) / log(logValue + 1)));


  if (abs(direction) != 1) {
    if (rightAngle < leftAngle) {
      move(speed, -speed);
    } else {
      move(-speed, speed);
    }
  } else if (direction == 1) {
    move(speed, -speed);
  } else if (direction == -1) {
    move(-speed, speed);
  }

  return inRange(gyroValue, target - threshold, target + threshold);
}

void Base::setLeftSetpoint(int setpoint) {
  leftController->setSetpoint(setpoint);
}

void Base::setRightSetpoint(int setpoint) {
  rightController->setSetpoint(setpoint);
}

void Base::lockLeft() {
  leftController->setSetpoint(getLeftEncoderValue());
}

void Base::lockRight() {
  rightController->setSetpoint(getRightEncoderValue());
}

void Base::loopLeft() {
  leftController->loop();
}

void Base::loopRight() {
  rightController->loop();
}

int Base::getLeftSetpoint() {
  return leftController->getSetpoint();
}

int Base::getRightSetpoint() {
  return rightController->getSetpoint();
}

bool Base::leftAtSetpoint() {
  return leftController->atSetpoint();
}

bool Base::rightAtSetpoint() {
  return rightController->atSetpoint();
}

void Base::resetGyro() {
  gyroReset(gyro);
}

int Base::getGyro() {
  return gyroGet(gyro); // In degrees
}

void Base::resetEncoders() {
  encoderReset(baseLeftEncoder);
  encoderReset(baseRightEncoder);
}

int Base::getLeftEncoderValue() {
  return encoderGet(baseLeftEncoder);
}

int Base::getRightEncoderValue() {
  return encoderGet(baseRightEncoder);
}

/*&int Base::getUltrasonic() {
  return ultrasonicGet(ultrasonic); // In centimeters
}*/

void Base::setMultiplier(float multiplier) {
  this->multiplier = multiplier;
}

void Base::setReference() {
  encoderReference = (int)((getRightEncoderValue() + getLeftEncoderValue()) / 2);
}

Base* Base::getInstance() {
    if (instance == 0) {
      instance = new Base();
    }

    return instance;
}
