#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"

#include "libIterativeRobot/Robot.h"

TurnWithGyro::TurnWithGyro(int turnDegrees) {
  requires(Robot::robotBase);
  this->degrees = turnDegrees;
  //this->motorSpeed = 0;
  //this->timeAtSetpoint = 0;
}

TurnWithGyro::TurnWithGyro(int turnDegrees, int motorSpeed) {
  requires(Robot::robotBase);
  this->degrees = turnDegrees;
  this->motorSpeed = motorSpeed;
  //this->timeAtSetpoint = 0;
}

bool TurnWithGyro::canRun() {
  //printf("TurnWithGyro(%d);\n", degrees);
  return true; // This is the default value anyways, so this method can be removed
}

void TurnWithGyro::initialize() {
  Robot::robotBase->initTurnWithGyro(degrees);
  // Perform any initialization steps for this command here, not in the
  // constructor
  // if (degrees != 0) {
  //   Robot::robotBase->resetGyro();
  // }
  // if (degrees > 0) {
  //   gyroPID = new PIDController(0.055, 0.0 , 0.002); // TUNE THIS
  //   //degrees -= 40;
  // } else {
  //   gyroPID = new PIDController(0.12, 0.0, 0.003); // Between 0.01 and 0.01125
  //   //degrees += 45;
  // }
  // gyroPID->setSensorValue(0);
  // gyroPID->setSetpoint(degrees);
  // //gyroPID->setThreshold(30);
  // //gyroPID->setMaxPIDSpeed(150);
  // this->timeAtSetpoint = 0;
}

void TurnWithGyro::execute() {
  Robot::robotBase->updateTurnWithGyro();
  // Code that runs when this command is scheduled to run
  //printf("Gyro value: %f\n", Robot::robotBase->getGyroValue());
  //printf("Hello, world!\n");
  // gyroPID->setSensorValue(Robot::robotBase->getGyroValue());
  // gyroPID->loop();
  // int motorSpeed = gyroPID->getOutput();
  //
  // Robot::robotBase->moveBase(-motorSpeed, motorSpeed);
}

bool TurnWithGyro::isFinished() {
  Robot::robotBase->atTurnTarget();
  // gyroPID->setSensorValue(Robot::robotBase->getGyroValue());
  // if (this->timeAtSetpoint == 0 && gyroPID->atSetpoint()) {
  //   this->timeAtSetpoint = pros::millis() + 250;
  // } else if (this->timeAtSetpoint == 0) {
  //   return false;
  // } else if (!gyroPID->atSetpoint()) {
  //   this->timeAtSetpoint = 0;
  //   return false;
  // }
  // bool isDone = gyroPID->atSetpoint();//pros::millis() > this->timeAtSetpoint;//
  // if (isDone) {
  // }
  // return isDone;
}

void TurnWithGyro::end() {
  Robot::robotBase->stopTurnWithGyro();
  Robot::robotBase->moveBase(0, 0);
  // Code that runs when isFinished() returns true.
  // Robot::robotBase->moveBase(0, 0);
  // delete gyroPID;
  // Robot::robotBase->resetGyro();
}

void TurnWithGyro::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
  Robot::robotBase->stopTurnWithGyro();
  Robot::robotBase->moveBase(0, 0);
  //delete gyroPID;
}
