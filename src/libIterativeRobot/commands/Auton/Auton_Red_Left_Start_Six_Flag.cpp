#include "libIterativeRobot/commands/Auton/Auton_Red_Left_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperTo.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"

#include "libIterativeRobot/commands/IndexerCommands/IndexerForwardTimed.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

#include "libIterativeRobot/commands/Auton/DoubleShot.h"

#include "libIterativeRobot/Robot.h"

Auton_Red_Left_Start_Six_Flag::Auton_Red_Left_Start_Six_Flag() {
  addSequentialCommand(new DriveLinear(3300, 3300));
  addParallelCommand(new CollectorForwardTimed(3000));
  addParallelCommand(new FlywheelBackwards());
  addSequentialCommand(new DriveLinear(-2850, -2850));
  addSequentialCommand(new DriveLinear(-680, 680));
  addSequentialCommand(new DriveLinear(1900, 1900));
  addParallelCommand(new DoubleShot());
  addSequentialCommand(new DriveLinear(-1000, -1000));
  //addSequentialCommand(new DriveLinear(500, 800));
  addSequentialCommand(new DriveLinear(2000, 2000));
  addSequentialCommand(new FlipperForwardTimed(500));
  //addSequentialCommand(new DriveLinear(-500, -800));
  addParallelCommand(new FlipperBackwardTimed(800));
  addSequentialCommand(new DriveLinear(-1300, -1300));
  addSequentialCommand(new DriveLinear(0, -700));
  addSequentialCommand(new FlipperTo(Robot::flipper->bottomLimit));
  addSequentialCommand(new DriveLinear(1000, 1000));
  addSequentialCommand(new FlipperTo(0));

  // addSequentialCommand(new DriveLinear(3500, 3500));
  // addParallelCommand(new FlywheelBackwards());
  // addParallelCommand(new CollectorForwardTimed(3000));
  // addSequentialCommand(new DriveLinear(-3000, -3000));
  // addSequentialCommand(new DriveLinear(-650, 650));
  // addSequentialCommand(new DriveLinear(1900, 1900));
  // addParallelCommand(new DoubleShot());
  // addSequentialCommand(new DriveLinear(500, 800));
  // addSequentialCommand(new FlipperForwardTimed(500));
  // addSequentialCommand(new DriveLinear(-500, -800));
  // addParallelCommand(new FlipperBackwardTimed(800));
  // addSequentialCommand(new DriveLinear(-1000, -1000));
  // addSequentialCommand(new DriveLinear(0, -700));
  // addSequentialCommand(new FlipperTo(Robot::flipper->bottomLimit));
  // addSequentialCommand(new DriveLinear(700, 700));
  // addSequentialCommand(new FlipperTo(0));

  // //addSequentialCommand(new FlipperTo(300));
  // addSequentialCommand(new FlipperForwardTimed(300));
  // addSequentialCommand(new DriveLinear(-400, -400));
  // addParallelCommand(new CollectorForwardTimed(1500));
  // //addSequentialCommand(new FlipperTo(Robot::flipper->bottomLimit));
  // addSequentialCommand(new FlipperBackwardTimed(100));
  // addSequentialCommand(new DriveLinear(-200, -200));
  // addSequentialCommand(new FlipperForwardTimed(50));
  // addSequentialCommand(new DriveLinear(300, 300));
  // addParallelCommand(new FlipperBackward(500));
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
