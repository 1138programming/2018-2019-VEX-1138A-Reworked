#include "libIterativeRobot/commands/Auton/Auton_Blue_Left_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"

#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForwardTimed.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

Auton_Blue_Left_Start_Six_Flag::Auton_Blue_Left_Start_Six_Flag() {
  //addSequentialCommand(new DriveToPosition(1250, -1250)); // Forwards one tile
  //addSequentialCommand(new DriveToPosition(-208, -208)); // Rotate 45 degrees
  //addSequentialCommand(new DriveToPosition(-30, -30)); // Rotate x degrees

  addSequentialCommand(new FlywheelRevUp());
}
