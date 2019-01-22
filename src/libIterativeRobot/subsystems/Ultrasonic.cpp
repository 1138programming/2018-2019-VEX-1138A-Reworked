#include "libIterativeRobot/subsystems/Ultrasonic.h"
#include "libIterativeRobot/commands/UltrasonicIdle.h"

Ultrasonic::Ultrasonic() {
  ultrasonic = new pros::ADIUltrasonic(1, 2); // echo, pings
}

int Ultrasonic::getUltrasonic() {
  return ultrasonic->get_value();
}

void Ultrasonic::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new UltrasonicIdle);
}
