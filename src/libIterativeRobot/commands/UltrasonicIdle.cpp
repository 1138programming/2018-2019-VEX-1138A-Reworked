#include "libIterativeRobot/commands/UltrasonicIdle.h"
#include "libIterativeRobot/subsystems/Ultrasonic.h"
#include "libIterativeRobot/Robot.h"

UltrasonicIdle::UltrasonicIdle() {
  requires(Robot::ultrasonic);
}

bool UltrasonicIdle::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void UltrasonicIdle::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void UltrasonicIdle::execute() {
  // Code that runs when this command is scheduled to run
  //printf("Ultrasonic(%d);\n", Robot::ultrasonic->getUltrasonic());
  if (Robot::ultrasonic->getUltrasonic() < 95 && Robot::ultrasonic->getUltrasonic() != -1) {
    //Robot::collector->runCollector(0);
  }
}

bool UltrasonicIdle::isFinished() {
  return false; // This is the default va  lue anyways, so this method can be removed
}

void UltrasonicIdle::end() {
  // Code that runs when isFinished() returns true.
}

void UltrasonicIdle::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
