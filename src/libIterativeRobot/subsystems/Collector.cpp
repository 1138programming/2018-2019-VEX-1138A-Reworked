#include "libIterativeRobot/subsystems/Collector.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorIdle.h"

Collector::Collector() {
  collectorMotor = Motor::getMotor(collectorMotorPort, collectorGearset);
}

void Collector::runFrontCollector(int velocity) {
  collectorMotor->getMotorObject()->move_velocity(velocity);
}


void Collector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new CollectorIdle());
}
