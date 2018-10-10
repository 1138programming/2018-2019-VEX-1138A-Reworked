#include "main.h"

Motor* Motor::motorInstances[MAX_MOTORS];
const pros::motor_gearset_e_t Motor::defaultGearset = pros::E_MOTOR_GEARSET_18;
const pros::motor_encoder_units_e_t Motor::defaultEncoderUnits = pros::E_MOTOR_ENCODER_COUNTS;

Motor::Motor(std::uint8_t channel, MotorType motorType) {
  this->motorType = motorType;
  if (motorType == v4) {
    this->v4Motor = new pros::ADIMotor(this->channel);
  } else {
    this->channel = channel;
    this->gearset = defaultGearset;
    this->encoderUnits = defaultEncoderUnits;
    this->v5Motor = new pros::Motor(this->channel, this->gearset, false, this->encoderUnits);
  }

  this->speed = 0;
  this->multiplier = 1;
  this->following = false;
  this->master = NULL;
  this->numFollowers = MAX_FOLLOWERS;
  for (unsigned int i = 0; i < this->numFollowers; i++) {
    this->followers[i] = NULL;
  }
  //this->numFollowers = sizeof(followers) / sizeof(followers[0])
}

MotorType Motor::getMotorType() {
  return this->motorType;
}



void Motor::setSpeed(int speed) {
  if (this->following)
    return;
  this->targetSpeed = (int)(confineToRange(speed) * this->multiplier);
  //printf("Moving master on port %d with speed %d\n", this->channel, this->speed);
  for (unsigned int i = 0; i < this->numFollowers; i++) {
      //printf("%d\n", followers[i]->channel);
      if (followers[i] != NULL) {
        //printf("Moving slave on port %d with speed %d\n", followers[i]->channel, this->speed);
        followers[i]->targetSpeed = this->targetSpeed;
      }
  }
}

int Motor::getSpeed() {
  return this->following ? this->master->getSpeed() : this->targetSpeed;
}

void Motor::reverse() {
  this->multiplier *= -1;
}

void Motor::init() {
  for (std::uint8_t i = 0; i < MAX_MOTORS; i++) {
    if (i <= 29)
      motorInstances[i] = new Motor(i + 1, v5);
    else
      motorInstances[i] = new Motor(i + 1, v4);
  }
}

void Motor::addFollower(Motor* motor) {
  if (this->following)
    return;

  for(unsigned int i = 0; i < motor->numFollowers; i++) {
    if (motor->followers[i] != NULL)
      return;
  }

  for (unsigned int i = 0; i < this->numFollowers; i++) {
    if (followers[i] == NULL) {
      followers[i] = motor;
      motor->setMaster(this);
      return;
    }
  }
}

void Motor::setMaster(Motor* motor) {
  this->following = true;
  this->master = motor;
}

int Motor::getChannel() {
  return this->channel;
}

void Motor::updateSlewRate() {
  // A bit of motor slewing to make sure that we don't stall
  int currSlewStep = this->targetSpeed - this->speed;
  currSlewStep = confineToRange(currSlewStep, -slewStep, slewStep); // This line may cause issues
  this->speed += currSlewStep;
}

pros::Motor* Motor::getMotorObject() {
  return this->v5Motor;
}

void Motor::move() {
  if (this->motorType == v4)
    this->v4Motor->set_value(this->speed);
  else
    this->v5Motor->move(this->speed);
}

void Motor::setEncoder(pros::ADIEncoder* encoder) {
  this->encoder = encoder;
}

std::int32_t Motor::getEncoderValue() {
  if (this->motorType == v4) {
    if (this->encoder != NULL)
      return this->encoder->get_value();
  } else {
    std::uint32_t time = pros::millis();
    return this->v5Motor->get_raw_position(&time);
  }
  return 0;
}

void Motor::periodicUpdate() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    //motorInstances[i]->updateSlewRate();
    motorInstances[i]->move();
  }
}

Motor* Motor::getMotor(int motorPort) {
  return motorInstances[motorPort - 1];
}

Motor* Motor::getMotor(Ports motorPort) {
  return motorInstances[motorPort - 1];
}
