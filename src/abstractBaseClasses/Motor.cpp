#include "main.h"

Motor* Motor::motorInstances[MAX_MOTORS];

Motor::Motor(int channel) {
  this->channel = channel;
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

void Motor::setSpeed(int speed) {
  if(this->following)
    return;
  this->targetSpeed = (int)(confineToRange(speed) * this->multiplier);
  //printf("Moving master on port %d with speed %d\n", this->channel, this->speed);
  for (unsigned int i = 0; i < this->numFollowers; i++) {
      //printf("%d\n", followers[i]->channel);
      if(followers[i] != NULL) {
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

void Motor::updateSlewRate() {
  // A bit of motor slewing to make sure that we don't stall
  int currSlewStep = this->targetSpeed - this->speed;
  currSlewStep = confineToRange(currSlewStep, -slewStep, slewStep); // This line may cause issues
  this->speed += currSlewStep;
  motorSet(this->channel, this->speed);
}

void Motor::periodicUpdate() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    motorInstances[i]->updateSlewRate();
  }
}

Motor* Motor::getMotor(int motorPort) {
  return motorInstances[motorPort - 1];
}
