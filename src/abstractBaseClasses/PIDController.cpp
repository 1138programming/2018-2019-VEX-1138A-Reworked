#include "abstractBaseClasses/PIDController.h"

std::vector<PIDController*> PIDController::instances; //  All values are initialized to 0

PIDController::PIDController(Motor* outputMotor, float kP, float kI, float kD) {
  this->outputMotor = outputMotor;
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  addInstance();
  //this->controllers.push_back(this);
}

PIDController::PIDController(float kP, float kI, float kD) {
  this->outputMotor = NULL;
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
}

void PIDController::addInstance() {
  instances.push_back(this);
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

void PIDController::setSetpointRelative(int setpoint) {
  this->setpoint = getSensorValue() + setpoint;
}

int PIDController::getSetpoint() {
  return this->setpoint;
}

/*void PIDController::setSensorEncoder(pros::ADIEncoder* encoder) {
  this->encoder = encoder;
  this->IMEaddress = 0;
  this->IMEset = false;
}*/

/*void PIDController::setSensorIME(unsigned char IMEaddress) {
  this->IMEaddress = IMEaddress;
  this->IMEset = true;
  this->encoder = NULL;
}*/

void PIDController::setSensorValue(int sensorValue) {
  currSensorValue = sensorValue;
}

int PIDController::getSensorValue() {
  if (outputMotor == NULL) {
    return currSensorValue;
  }
  return outputMotor->getEncoderValue();
}

int PIDController::getOutput() {
  return output;
}

void PIDController::setThreshold(int threshold) {
  this->threshold = threshold;
}

void PIDController::loop() {
  //printf("PID is looping\n");
  currSensorValue = getSensorValue();
  deltaTime = pros::millis() - lastTime;
  lastTime = pros::millis();
  error = setpoint - currSensorValue;
  integral += error * (deltaTime / 1000);
  derivative  = (error - previousError) / (deltaTime / 1000);
  output = (int)(kP * error + kI * integral + kD * derivative * scalar);
  int sign = output < 0 ? output == 0 ? -1 : 0 : 1;
  //int sign = 0;
  output = confineToRange(output + (sign * 12));
  //printf("Current sensor value is %d\n", currSensorValue);
  //printf("Error is %d, integral is %f, derivative is %f, and output is %d\n", error, integral, derivative, output);
  //printf("Error is %d and output is %d\n", error, output);
  // if (this->outputMotor->getChannel() == 10) {
  //   printf("Wrist output is %d\n", output);
  // }
  if (outputMotor != NULL) {
    outputMotor->getMotorObject()->move_velocity(output);
  }
  //printf("Error is %d, output is %d\n", error, output);
  previousError = error;
}

void PIDController::lock() {
  setSetpoint(getSensorValue());
}

void PIDController::setMaxPIDSpeed(int maxSpeed) {
  this->scalar = maxSpeed / KMaxMotorSpeed;
}

bool PIDController::atSetpoint() {
  currSensorValue = getSensorValue();
  bool range = inRange(currSensorValue, setpoint - threshold, setpoint + threshold);
  bool smallDerivative = fabs(derivative) < 0.1;
  bool atSetpoint = range && smallDerivative; // Checks if the sensor value is within a threshold of the target and whether the derivative is less than 0.1
  return atSetpoint;
}

void PIDController::loopAll() {
  for (size_t i = 0; i < instances.size(); i++) {
    if (instances[i]->enabled)
      instances[i]->loop();
  }
}
