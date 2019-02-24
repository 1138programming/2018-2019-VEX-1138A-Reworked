#include "libIterativeRobot/commands/Auton/Auton_Blue_Left_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"

#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForwardTimed.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

Auton_Blue_Left_Start_Six_Flag::Auton_Blue_Left_Start_Six_Flag() {
  bool isRed = false;
  addSequentialCommand(new FlywheelBackwards());
  addParallelCommand(new DriveLinear(3300, 600));
  addParallelCommand(new CollectorForwardTimed(1850));
  addSequentialCommand(new DriveLinear(-2950));
  addParallelCommand(new CollectorForwardTimed(250));
  addSequentialCommand(new TurnWithGyro(900 * (isRed ? -1 : 1)));

  addParallelCommand(new CollectorForwardTimed(500));

  // ISSUE HERE
  addSequentialCommand(new DriveLinear(100, 50));
  addParallelCommand(new MiddleCollectorForwardTimed(250));
  addParallelCommand(new CollectorForwardTimed(300));
  
  addSequentialCommand(new DriveLinear(1750));
  addParallelCommand(new CollectorForwardTimed(1000));
  addSequentialCommand(new MiddleCollectorForwardTimed(500));
  addParallelCommand(new CollectorForwardTimed(500));

  addSequentialCommand(new DriveLinear(150));
  addSequentialCommand(new DriveLinear(200));
  addParallelCommand(new FlipperForwardTimed(250));
  addSequentialCommand(new DriveLinear(-1150));
  addParallelCommand(new FlipperBackwardTimed(400));

  // Go back and collect off of the cap
  addSequentialCommand(new DelayCommand(250));
  addSequentialCommand(new TurnWithGyro(-900 * (isRed ? -1 : 1)));
  addSequentialCommand(new DelayCommand(150));
  addSequentialCommand(new DriveLinear(225, 100));
  addSequentialCommand(new CollectorForwardTimed(750));
  addParallelCommand(new FlipperForwardTimed(750));
  addSequentialCommand(new FlipperForwardTimed(750));
  addParallelCommand(new DriveLinear(-350, 25));
  addSequentialCommand(new DriveLinear(550));
  addSequentialCommand(new CollectorForwardTimed(750));
  addSequentialCommand(new FlipperBackwardTimed(500));

  // Now realign and shoot the flags
  addSequentialCommand(new TurnWithGyro(300 * (isRed ? -1 : 1)));
  addParallelCommand(new CollectorForwardTimed(500));
  addSequentialCommand(new MiddleCollectorForwardTimed(500));
}
