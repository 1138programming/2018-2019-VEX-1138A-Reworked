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
  //addSequentialCommand(new FlywheelBackwards());
  addSequentialCommand(new DriveLinear(3050));
  addParallelCommand(new CollectorForwardTimed(2250));
  addSequentialCommand(new DriveLinear(-2950));
  addParallelCommand(new CollectorForwardTimed(250));
  addSequentialCommand(new DriveLinear(200));
  addSequentialCommand(new DelayCommand(250));
  addSequentialCommand(new TurnWithGyro(-900));

  addParallelCommand(new CollectorForwardTimed(1000));
  addSequentialCommand(new DelayCommand(250));

  // ISSUE HERE
  // addSequentialCommand(new DriveLinear(300, 50));
  // addSequentialCommand(new MiddleCollectorForwardTimed(300));
  // addParallelCommand(new CollectorForwardTimed(300));
  
  // addSequentialCommand(new DriveLinear(1950, 50));
  // addParallelCommand(new CollectorForwardTimed(1000));
  // addSequentialCommand(new MiddleCollectorForwardTimed(500));
  // addParallelCommand(new CollectorForwardTimed(500));

  // addSequentialCommand(new DriveLinear(200, 50));
  // addSequentialCommand(new DriveLinear(400, 50));
  // addParallelCommand(new FlipperForwardTimed(150));
  // addSequentialCommand(new DelayCommand(250));
  // addSequentialCommand(new DriveLinear(-1250, 50));
  // addParallelCommand(new FlipperBackwardTimed(400));

  // Go back and collect off of the cap
  // addSequentialCommand(new DelayCommand(250));
  // addSequentialCommand(new TurnWithGyro(900));
  //addSequentialCommand(new DelayCommand(250));
  //addSequentialCommand(new DriveLinear(425, 25));
  //addSequentialCommand(new CollectorForwardTimed(2000));
  //addParallelCommand(new FlipperForwardTimed(750));
}
