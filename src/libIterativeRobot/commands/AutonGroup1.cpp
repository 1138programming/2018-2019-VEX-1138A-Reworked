#include "libIterativeRobot/commands/AutonGroup1.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"

AutonGroup1::AutonGroup1() {
  //addSequentialCommand(new DriveToPosition(1250, -1250)); // Forwards one tile
  //addSequentialCommand(new DriveToPosition(-208, -208)); // Rotate 45 degrees
  //addSequentialCommand(new DriveToPosition(-30, -30)); // Rotate x degrees

  addSequentialCommand(new FlywheelRevUp());
  addSequentialCommand(new CollectorMiddleForwardTimed(500));

  addSequentialCommand(new DriveToPosition(2750, -2750));
  //addSequentialCommand(new DelayCommand(500));
  addSequentialCommand(new DriveToPosition(-2750, 2750));

  //addSequentialCommand(new DriveToPosition(-650, -650));
  //addSequentialCommand(new DriveToPosition(2500, -2500));
  //addParallelCommand(new CollectorForwardTimed(2500));
  //addSequentialCommand(new CollectorMiddleForwardTimed(1250));
  //addParallelCommand(new CollectorForwardTimed(500));

  //addSequentialCommand(new DriveToPosition(1000, 1000));
  //addParallelCommand(new FlywheelRevUp());
  //addSequentialCommand(new CollectorMiddleForwardTimed(1000));
}
