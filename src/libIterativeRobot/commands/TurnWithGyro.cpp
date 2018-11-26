#include "libIterativeRobot/commands/TurnWithGyro.h"
#include "libIterativeRobot/Robot.h"

TurnWithGyro::TurnWithGyro(int turnDegrees) {
  requires(Robot::robotBase);
  this->degrees = turnDegrees;
  this->motorSpeed = 0;
}

TurnWithGyro::TurnWithGyro(int turnDegrees, int motorSpeed) {
  requires(Robot::robotBase);
  this->degrees = turnDegrees;
  this->motorSpeed = motorSpeed;
}

bool TurnWithGyro::canRun() {
  //printf("TurnWithGyro(%d);\n", degrees);
  return true; // This is the default value anyways, so this method can be removed
}

void TurnWithGyro::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  Robot::robotBase->resetGyro();
  gyroPID = new PIDController(0.05, 0.0 , 0.002);
  gyroPID->setSensorValue(0);
  gyroPID->setSetpoint(degrees);
}

void TurnWithGyro::execute() {
  // Code that runs when this command is scheduled to run
  printf("Gyro value: %f\n", Robot::robotBase->getGyroValue());
  //printf("Hello, world!\n");
  gyroPID->setSensorValue(Robot::robotBase->getGyroValue());
  gyroPID->loop();
  int motorSpeed = gyroPID->getOutput();

  Robot::robotBase->moveBase(-motorSpeed, motorSpeed);
}

bool TurnWithGyro::isFinished() {
  return false; //gyroPID->atSetpoint(); // This is the default value anyways, so this method can be removed
}

void TurnWithGyro::end() {
  // Code that runs when isFinished() returns true.
  Robot::robotBase->moveBase(0, 0);
  delete gyroPID;
}

void TurnWithGyro::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  delete gyroPID;
}
