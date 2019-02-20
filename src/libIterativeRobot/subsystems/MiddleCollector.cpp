#include "libIterativeRobot/subsystems/MiddleCollector.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorIdle.h"

MiddleCollector::MiddleCollector() {
  middleCollectorMotor = Motor::getMotor(middleCollectorMotorPort);

  ultrasonic = new pros::ADIUltrasonic(1, 2); // echo, pings
}

void MiddleCollector::runMiddleCollector(int velocity) {
  middleCollectorMotor->getMotorObject()->move_velocity(velocity);
}

int MiddleCollector::getUltrasonic() {
  return ultrasonic->get_value();
}

void MiddleCollector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new MiddleCollectorIdle());
}
