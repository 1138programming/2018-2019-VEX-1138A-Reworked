#include "libIterativeRobot/commands/Auton/Auton_Blue_Left_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"

#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForwardTimed.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

Auton_Blue_Left_Start_Six_Flag::Auton_Blue_Left_Start_Six_Flag() {
  addSequentialCommand(new TurnWithGyro(-900));
}
