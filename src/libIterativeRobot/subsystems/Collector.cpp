#include "libIterativeRobot/subsystems/Collector.h"
#include "libIterativeRobot/commands/CollectorIdle.h"

Collector::Collector() {
  frontCollectorMotor = Motor::getMotor(frontCollectorMotorPort);
  frontCollectorMotor->reverse();
  // Slaving will be tested after initial test
}

void Collector::runCollector(int velocity) {
  frontCollectorMotor->setSpeed(-velocity);
}

void Collector::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new CollectorIdle());
}
