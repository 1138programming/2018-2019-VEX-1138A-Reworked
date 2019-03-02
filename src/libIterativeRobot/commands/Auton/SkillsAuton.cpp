#include "libIterativeRobot/commands/Auton/SkillsAuton.h"

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

SkillsAuton::SkillsAuton() {
  bool isRed = true;
  addSequentialCommand(new FlywheelBackwards());
  addParallelCommand(new DriveLinear(3400, 600));
  addParallelCommand(new CollectorForwardTimed(1850));

  // But in skills... we move backwards, use the tusk, 
  addSequentialCommand(new DriveLinear(-600));
  addSequentialCommand(new FlipperForwardTimed(250));
  addSequentialCommand(new DriveLinear(600));
  addSequentialCommand(new FlipperBackwardTimed(500));

  addSequentialCommand(new DriveLinear(-2800));
  addParallelCommand(new CollectorForwardTimed(500));
  addSequentialCommand(new TurnWithGyro(900 * (isRed ? -1 : 1)));

  addParallelCommand(new CollectorForwardTimed(500));

  // ISSUE HERE
  addSequentialCommand(new DriveLinear(200, 50));
  addParallelCommand(new MiddleCollectorForwardTimed(250));
  addParallelCommand(new CollectorForwardTimed(300));
  
  addSequentialCommand(new DriveLinear(1800));
  addParallelCommand(new CollectorForwardTimed(1000));
  addSequentialCommand(new MiddleCollectorForwardTimed(500));
  addParallelCommand(new CollectorForwardTimed(500));

  addSequentialCommand(new DriveLinear(600));
  addSequentialCommand(new DriveLinear(200));
  addParallelCommand(new FlipperForwardTimed(200));
  addSequentialCommand(new DriveLinear(-1200));
  addParallelCommand(new FlipperBackwardTimed(400));

  addSequentialCommand(new TurnWithGyro(-900 * (isRed ? -1 : 1)));
  addParallelCommand(new FlipperForwardTimed(750));
  addSequentialCommand(new DriveLinear(580));
  addSequentialCommand(new FlipperBackwardTimed(500));

  addSequentialCommand(new DriveLinear(-2500)); // Hit the wall, let's realign for the platform

  addSequentialCommand(new DriveLinear(300));
  addSequentialCommand(new TurnWithGyro(900));
  addSequentialCommand(new DriveLinear(3300));

  addSequentialCommand(new TurnWithGyro(-900));

  addSequentialCommand(new DriveLinear(1100));
  addSequentialCommand(new FlipperForwardTimed(500));
  addSequentialCommand(new FlipperForwardTimed(500));
  addParallelCommand(new DriveLinear(3000));
  addSequentialCommand(new FlipperBackwardTimed(500));
  addSequentialCommand(new DriveLinear(50));
  addSequentialCommand(new FlipperForwardTimed(500));
  addSequentialCommand(new FlipperForwardTimed(500));
  addParallelCommand(new DriveLinear(2300));

}
