#include "libIterativeRobot/commands/FlipperCommands/FlipperMonitor.h"

#include "libIterativeRobot/Robot.h"

FlipperMonitor::FlipperMonitor() {
  //requires(Robot::flipper);
}

bool FlipperMonitor::canRun() {
  //printf("Last time is %d\n", lastTime);
  return pros::millis() > (lastTime + 1500);
}

void FlipperMonitor::initialize() {
  // Perform any initialization steps for this command here, not in the
  // constructor
  printf("Running the flipper monitor\n");
  lastTime = pros::millis();
}

void FlipperMonitor::execute() {
  // Code that runs when this command is scheduled to run

  //Robot::mainController->set_text(0, 0, "Flipper");
  //Robot::mainController->print(0, 0, "Enabled: %d", Robot::flipper->getPID()->isEnabled());
  Robot::partnerController->print(0, 0, "Setpoint: %d", Robot::flipper->getPID()->getSetpoint());
  //Robot::mainController->clear();
  //Robot::mainController->print(2, 0, "Value: %d", Robot::flipper->getEncoderValue());
  //printf("Moving flipper to %d\n", target);
  //Robot::flipper->runFlipper(-42);
}

bool FlipperMonitor::isFinished() {
  return true;
}

void FlipperMonitor::end() {
  // Code that runs when isFinished() returns true.
}

void FlipperMonitor::interrupted() {
  // Code that runs when this command is interrupted by another one
  // with a higher priority.
}
