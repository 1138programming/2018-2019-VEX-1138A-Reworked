#include "libIterativeRobot/commands/Red_Left_Start_Six_Flag.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorBackwardsTimed.h"
#include "libIterativeRobot/commands/MiddleCollectorForwardTimed.h"
#include "libIterativeRobot/commands/MiddleCollectorBackwardsTimed.h"
#include "libIterativeRobot/commands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperBackwardsTimed.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"

Red_Left_Start_Six_Flag::Red_Left_Start_Six_Flag() {
  //addSequentialCommand(new DriveToPosition(1250, -1250)); // Forwards one tile
  //addSequentialCommand(new DriveToPosition(-208, -208)); // Rotate 45 degrees
  //addSequentialCommand(new DriveToPosition(-30, -30)); // Rotate x degrees

  addSequentialCommand(new FlywheelRevUp());
}