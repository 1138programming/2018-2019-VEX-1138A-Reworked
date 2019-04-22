#include "libIterativeRobot/subsystems/Indexer.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerIdle.h"

Indexer::Indexer() {
  indexerMotor = Motor::getMotor(indexerMotorPort, indexerGearset);

  ultrasonic = new pros::ADIUltrasonic(ultrasonicEchoPort, ultrasonicPingPort); // echo, pings
}

void Indexer::runIndexer(int velocity) {
  indexerMotor->getMotorObject()->move_velocity(velocity);
}

double Indexer::getEncoderValue() {
  return indexerMotor->getEncoderValue();
}

int Indexer::getUltrasonic() {
  return ultrasonic->get_value();
}

void Indexer::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new IndexerIdle());
}
