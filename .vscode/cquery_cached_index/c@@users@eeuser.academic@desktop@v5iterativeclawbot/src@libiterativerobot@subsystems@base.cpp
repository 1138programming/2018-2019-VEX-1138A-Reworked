#include "libIterativeRobot/subsystems/Base.h"
#include "libIterativeRobot/commands/ExampleCommand.h"

Base::Base() {
  // If you want to set a default command to run when this subsystem
  // is idle, uncomment and modify the following line of code:
  // setDefaultCommand(new ExampleCommand());
}

void Base::initDefaultCommand() {
  // Setup up a default command here
  setDefaultCommand(new ExampleCommand());
}
