#include "libIterativeRobot/commands/Auton/Auton_Red_Right_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"
#include "libIterativeRobot/commands/BaseCommands/BrakeBaseFor.h"

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

#include "libIterativeRobot/Robot.h"

Auton_Red_Right_Start_Six_Flag::Auton_Red_Right_Start_Six_Flag() {
  // addSequentialCommand(new DriveLinear(450, -450));
  // addParallelCommand(new FlipperTo(Robot::flipper->bottomLimit));
  // addSequentialCommand(new DelayCommand(1000));
  // addSequentialCommand(new FlipperTo(0));

  addSequentialCommand(new FlywheelRevUp(116));
  addSequentialCommand(new DriveLinear(3500, 3500));
  addParallelCommand(new CollectorForwardTimed(2000));
  addSequentialCommand(new DriveLinear(-1600, -1600));
  addSequentialCommand(new DriveLinear(630, -630));
  addSequentialCommand(new DriveLinear(1300, 1300));
  addSequentialCommand(new DriveLinear(-630, 630));
  addSequentialCommand(new FlipperTo(Robot::flipper->bottomLimit));
  addSequentialCommand(new DriveLinear(800, 800));
  addSequentialCommand(new FlipperTo(0));
  addSequentialCommand(new DriveLinear(-920, 0));
  addSequentialCommand(new IndexerForwardTimed(500));
  addSequentialCommand(new FlywheelRevUp(108));
  addSequentialCommand(new DelayCommand(1000));
  addSequentialCommand(new IndexerForwardTimed(500));
  addParallelCommand(new CollectorForwardTimed(500));
  addSequentialCommand(new DriveLinear(300, 300));
  addSequentialCommand(new DriveLinear(220, 600));
  addSequentialCommand(new DriveLinear(4200, 4200));
  //addSequentialCommand(new DriveLinear(-1600, -100));
  //addSequentialCommand(new DelayCommand(1000));

  // bool isRed = true;
  // addSequentialCommand(new DriveLinear(3000, 50));
  // addParallelCommand(new CollectorForwardTimed(3000));
  // addSequentialCommand(new DriveLinear(-750, 50));
  // addSequentialCommand(new TurnWithGyro(-700 * (isRed ? -0.9 : 1)));
  // addSequentialCommand(new DriveLinear(1300, 50));
  // addParallelCommand(new FlipperForwardTimed(200));
  // addSequentialCommand(new FlipperBackwardTimed(350));
  // addSequentialCommand(new DriveLinear(-1300 * (isRed ? 0.9 : 1), 50));
  // addSequentialCommand(new TurnWithGyro(1650 * (isRed ? -0.95 : 1)));
  // addSequentialCommand(new DriveLinear(140, 50));
  // addSequentialCommand(new FlipperForwardTimed(450));
  // addSequentialCommand(new DriveLinear(2700));
  // addParallelCommand(new FlipperForwardTimed(1950));
  // addSequentialCommand(new BrakeBaseFor(500));
}
