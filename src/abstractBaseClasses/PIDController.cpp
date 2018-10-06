#include "main.h"

PIDController* PIDController::instances[MAX_MOTORS] = {0}; //  All values are initialized to 0

PIDController::PIDController(Motor* outputMotor, float kP, float kI, float kD) {
  this->outputMotor = outputMotor;
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  addInstance();
  //this->controllers.push_back(this);
}

void PIDController::addInstance() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    if (instances[i] == 0) {
      instances[i] = this;
      return;
    }
  }
}

void PIDController::setKp(float kP) {
  this->kP = kP;
}

void PIDController::setKi(float kI) {
  this->kI = kI;
}

void PIDController::setKd(float kD) {
  this->kD = kD;
}

void PIDController::setSetpoint(int setpoint) {
  //printf("Setpoint set to %d\n", setpoint);
  this->setpoint = setpoint;
  integral = 0;
}

int PIDController::getSetpoint() {
  return this->setpoint;
}

void PIDController::setSensorEncoder(Encoder encoder) {
  this->encoder = encoder;
  this->IMEaddress = 0;
  this->IMEset = false;
}

void PIDController::setSensorIME(unsigned char IMEaddress) {
  this->IMEaddress = IMEaddress;
  this->IMEset = true;
  this->encoder = NULL;
}

int PIDController::getSensorValue() {
  if (encoder != NULL)
    return encoderGet(encoder);
  else if (IMEset) {
      int value;
      imeGet(IMEaddress, &value);
      return value;
  }

  return 0;
}

void PIDController::setThreshold(int threshold) {
  this->threshold = threshold;
}

void PIDController::loop() {
  //printf("PID is looping\n");
  currSensorValue = getSensorValue();
  deltaTime = millis() - lastTime;
  lastTime = millis();
  error = setpoint - currSensorValue;
  integral += error * (deltaTime / 1000);
  derivative  = (error - previousError) / (deltaTime / 1000);
  output = (int)(kP * error + kI * integral + kD * derivative);
  int sign = output < 0 ? output == 0 ? -1 : 0 : 1;
  //int sign = 0;
  output = confineToRange(output + (sign * 12));
  printf("Current sensor value is %d\n", currSensorValue);
  //printf("Error is %d, integral is %f, derivative is %f, and output is %d\n", error, integral, derivative, output);
  //printf("Error is %d and output is %d\n", error, output);
  // if (this->outputMotor->getChannel() == 10) {
  //   printf("Wrist output is %d\n", output);
  // }
  outputMotor->setSpeed(output);
  //printf("Error is %d, output is %d\n", error, output);
  previousError = error;
}

void PIDController::lock() {
  setSetpoint(getSensorValue());
}

bool PIDController::atSetpoint() {
  bool atSetpoint = inRange(this->currSensorValue, setpoint - threshold, setpoint + threshold) && fabs(derivative) < 0.1;
  return atSetpoint;
}

void PIDController::loopAll() {
  for (int i = 0; i < MAX_MOTORS; i++) {
    if(instances[i]->enabled)
      instances[i]->loop();
  }
}
