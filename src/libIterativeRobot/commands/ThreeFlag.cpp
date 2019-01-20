#include "libIterativeRobot/commands/ThreeFlag.h"
#include "libIterativeRobot/commands/ThreeFlagSubgroup.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/FlywheelForward.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/TurnWithGyro.h"
#include "libIterativeRobot/commands/ResetGyro.h"
#include "libIterativeRobot/commands/FlipperForwardTimed.h"

ThreeFlag::ThreeFlag() {
  // addSequentialCommand(new ResetGyro());
  // addSequentialCommand(new DriveToPosition(3250, 3250));
  // addParallelCommand(new FlipperForwardTimed(500));
  // addParallelCommand(new FlywheelForward());
  //
  // addParallelCommand(new CollectorForwardTimed(1500));
  // addSequentialCommand(new CollectorMiddleForwardTimed(500));
  // addParallelCommand(new CollectorForwardTimed(500));
  //
  // addSequentialCommand(new DelayCommand(150));
  // addSequentialCommand(new TurnWithGyro(0));
  //
  // addSequentialCommand(new DriveToPosition(-4500, -4500));
  //
  // // Turn now
  // addSequentialCommand(new DelayCommand(250));
  // addSequentialCommand(new DriveToPosition(345, 345));
  //
  // addSequentialCommand(new DelayCommand(150));

  TurnWithGyro* test = new TurnWithGyro(900);
  printf("Address of test: 0x%x", test);

  addSequentialCommand(test); // - for BLUE

  addSequentialCommand(new DelayCommand(150));

  // addSequentialCommand(new DriveToPosition(200, 200));
  // addSequentialCommand(new FlywheelRevUp());
  // addSequentialCommand(new CollectorMiddleForwardTimed(500)); // Shoot first ball to top flag
  // addSequentialCommand(new DelayCommand(250));
  // // Move forward and shoot the middle flag
  // addSequentialCommand(new DriveToPosition(800, 800));
  // addSequentialCommand(new CollectorMiddleForwardTimed(1500));
  // addSequentialCommand(new DelayCommand(150));
  // // Hit the bottom flag
  // addSequentialCommand(new DriveToPosition(2400, 2400));
  // addSequentialCommand(new DelayCommand(150));
  //
  // addSequentialCommand(new DriveToPosition(-400, -400));
  // addSequentialCommand(new TurnWithGyro(0));
  // addSequentialCommand(new DriveToPosition(-4400, -4400));
  // addSequentialCommand(new DelayCommand(150));
  // Turn onto the platform
  addSequentialCommand(new TurnWithGyro(-900));
  addSequentialCommand(new DelayCommand(150));
  addSequentialCommand(new DriveToPosition(250, 250)); // 6000

}
