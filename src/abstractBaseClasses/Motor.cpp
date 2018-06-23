#include "main.h"

Motor* Motor::motorInstances[MAX_MOTORS];

Motor::Motor(int channel) {
  this->channel = channel;
  this->multiplier = 1;
  this->following = false;
  this->master = NULL;
  this->numFollowers = MAX_FOLLOWERS;
  for (unsigned int i = 0; i < this->numFollowers; i++) {
    this->followers[i] = NULL;
  }
  //this->numFollowers = sizeof(followers) / sizeof(followers[0])
}

void Motor::setSpeed(int speed) {
  if(this->following)
    return;
  this->speed = (int)(confineToRange(speed) * this->multiplier);
  //printf("Moving master on port %d with speed %d\n", this->channel, this->speed);
  motorSet(this->channel, this->speed);
  for (unsigned int i = 0; i < this->numFollowers; i++) {
      //printf("%d\n", followers[i]->channel);
      if(followers[i] != NULL) {
        //printf("Moving slave on port %d with speed %d\n", followers[i]->channel, this->speed);
        followers[i]->speed = this->speed;
        motorSet(followers[i]->channel, followers[i]->multiplier * this->speed);
      }
  }
}

int Motor::getSpeed() {
  return this->following ? this->master->getSpeed() : this->speed;
}

void Motor::reverse() {
  this->multiplier = -1;
}

void Motor::init() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    motorInstances[i] = new Motor(i + 1);
  }
}

void Motor::addFollower(Motor* motor) {
  if(this->following)
    return;

  for(unsigned int i = 0; i < motor->numFollowers; i++) {
    if(motor->followers[i] != NULL)
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

Motor* Motor::getMotor(int motorPort) {
  return motorInstances[motorPort - 1];
}
