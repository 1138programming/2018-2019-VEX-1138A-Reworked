#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"

#include "libIterativeRobot/Robot.h"

FlywheelRevUp::FlywheelRevUp(int speed) {
  priority = 45; // Less priority, so that we can be interrupted when we actually want to shoot
  requires(Robot::flywheel);

  this->speed = speed;
}

bool FlywheelRevUp::canRun() {
  return true; // This is the default value anyways, so this method can be removed
}

void FlywheelRevUp::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
}

void FlywheelRevUp::execute() {
  // Code that runs when this command is scheduled to run
  Robot::flywheel->setFlywheel(speed);
}

bool FlywheelRevUp::isFinished() {
  //return abs(Robot::flywheel->getFlywheelVelocity()) > 570; // This is the default va  lue anyways, so this method can be removed
  return true;
}

void FlywheelRevUp::end() {
  // Code that runs when isFinished() returns true.
}

void FlywheelRevUp::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
