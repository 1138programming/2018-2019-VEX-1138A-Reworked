#include "libIterativeRobot/commands/Auton/Auton_Blue_Left_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
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
  addSequentialCommand(new FlywheelBackwards());
  addSequentialCommand(new DriveToPosition(3250, 3250));
  addParallelCommand(new CollectorForwardTimed(2250));
  addSequentialCommand(new DriveToPosition(-3450, -3450));
  addParallelCommand(new CollectorForwardTimed(250));
  addSequentialCommand(new TurnWithGyro(-900));
  addSequentialCommand(new DelayCommand(2000));

  //addSequentialCommand(new DriveToPosition(200, 200, 100));
  addSequentialCommand(new MiddleCollectorForwardTimed(5000));
  addParallelCommand(new CollectorForwardTimed(5000));

  addSequentialCommand(new DelayCommand(5000));
  //addSequentialCommand(new DriveToPosition(1450, 1450, 50));

  addSequentialCommand(new MiddleCollectorForwardTimed(5000));
  addParallelCommand(new CollectorForwardTimed(5000));

  addSequentialCommand(new DelayCommand(5000));
  addSequentialCommand(new DriveToPosition(200, 200, 50));
  //addSequentialCommand(new DriveToPosition(400, 400, 50));
  addParallelCommand(new FlipperForwardTimed(150));
  addSequentialCommand(new DelayCommand(250));
  addSequentialCommand(new DriveToPosition(-550, -550, 50));
  addParallelCommand(new FlipperBackwardTimed(400));

  // Go back and collect off of the cap
  //addSequentialCommand(new DelayCommand(250));
  //addSequentialCommand(new TurnWithGyro(900));
  //addSequentialCommand(new DelayCommand(250));
  //addSequentialCommand(new DriveToPosition(425, 425, 25));
  //addSequentialCommand(new CollectorForwardTimed(2000));
  //addParallelCommand(new FlipperForwardTimed(750));
}
