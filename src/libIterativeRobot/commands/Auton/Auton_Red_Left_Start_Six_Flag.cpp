#include "libIterativeRobot/commands/Auton/Auton_Red_Left_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"

#include "libIterativeRobot/commands/IndexerCommands/IndexerForwardTimed.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

Auton_Red_Left_Start_Six_Flag::Auton_Red_Left_Start_Six_Flag() {
  addSequentialCommand(new DriveLinear(500));
  //addSequentialCommand(new DelayCommand(1000));
  /*bool isRed = true;
  addSequentialCommand(new FlywheelBackwards());
  addParallelCommand(new DriveLinear(3400, 600));
  addParallelCommand(new CollectorForwardTimed(1850));
  addSequentialCommand(new DriveLinear(-2780));
  addParallelCommand(new CollectorForwardTimed(500));
  addSequentialCommand(new TurnWithGyro(900 * (isRed ? -1 : 1)));

  addParallelCommand(new CollectorForwardTimed(500));

  // ISSUE HERE
  addSequentialCommand(new DriveLinear(200, 50));
  addParallelCommand(new IndexerForwardTimed(250));
  addParallelCommand(new CollectorForwardTimed(300));

  addSequentialCommand(new DriveLinear(1800));
  addParallelCommand(new CollectorForwardTimed(1000));
  addSequentialCommand(new IndexerForwardTimed(500));
  addParallelCommand(new CollectorForwardTimed(500));

  addSequentialCommand(new DriveLinear(600));
  addSequentialCommand(new DriveLinear(200));
  addParallelCommand(new FlipperForwardTimed(200));
  addSequentialCommand(new DriveLinear(-1100));
  addParallelCommand(new FlipperBackwardTimed(400));

  addSequentialCommand(new TurnWithGyro(-900 * (isRed ? -1 : 1)));
  addParallelCommand(new FlipperForwardTimed(750));
  addSequentialCommand(new DriveLinear(580));
  addSequentialCommand(new FlipperBackwardTimed(500));*/
}
