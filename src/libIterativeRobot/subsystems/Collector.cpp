#include "libIterativeRobot/subsystems/Collector.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorIdle.h"

Collector::Collector() {
  frontCollectorMotor = Motor::getMotor(frontCollectorMotorPort);
}

void Collector::runFrontCollector(int velocity) {
  frontCollectorMotor->getMotorObject()->move_velocity(velocity);
}


void Collector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new CollectorIdle());
}
