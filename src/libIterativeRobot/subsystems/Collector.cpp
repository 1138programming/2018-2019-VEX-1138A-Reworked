#include "libIterativeRobot/subsystems/Collector.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorIdle.h"

Collector::Collector() {
  frontCollectorMotor = Motor::getMotor(frontCollectorMotorPort);
  middleCollectorMotor = Motor::getMotor(middleCollectorMotorPort);

  ultrasonic = new pros::ADIUltrasonic(1, 2); // echo, pings
}

void Collector::runFrontCollector(int velocity) {
  frontCollectorMotor->getMotorObject()->move_velocity(velocity);
}

void Collector::runMiddleCollector(int velocity) {
  middleCollectorMotor->getMotorObject()->move_velocity(velocity);
}

int Collector::getUltrasonic() {
  return ultrasonic->get_value();
}

void Collector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new CollectorIdle());
}
