#include "libIterativeRobot/commands/Auton/Auton_Red_Right_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"
#include "libIterativeRobot/commands/BaseCommands/BrakeBaseFor.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"

#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForwardTimed.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

Auton_Red_Right_Start_Six_Flag::Auton_Red_Right_Start_Six_Flag() {
  bool isRed = true;
  addSequentialCommand(new DriveLinear(3000, 50));
  addParallelCommand(new CollectorForwardTimed(3000));
  addSequentialCommand(new DriveLinear(-750, 50));
  addSequentialCommand(new TurnWithGyro(-700 * (isRed ? -0.9 : 1)));
  addSequentialCommand(new DriveLinear(1300, 50));
  addParallelCommand(new FlipperForwardTimed(200));
  addSequentialCommand(new FlipperBackwardTimed(350));
  addSequentialCommand(new DriveLinear(-1300 * (isRed ? 0.9 : 1), 50));
  addSequentialCommand(new TurnWithGyro(1650 * (isRed ? -0.95 : 1)));
  addSequentialCommand(new DriveLinear(140, 50));
  addSequentialCommand(new FlipperForwardTimed(450));
  addSequentialCommand(new DriveLinear(2700));
  addParallelCommand(new FlipperForwardTimed(1950));
  addSequentialCommand(new BrakeBaseFor(500));
}
