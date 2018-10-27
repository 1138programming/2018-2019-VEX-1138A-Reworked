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
  addSequentialCommand(new DelayCommand(150));

  addSequentialCommand(new DriveToPosition(3050, -3050));
  //addSequentialCommand(new DelayCommand(500));
  addSequentialCommand(new DelayCommand(150));

  if (false) {
    addSequentialCommand(new DriveToPosition(-3400, 3400));
    addSequentialCommand(new DelayCommand(250));

    // Turn and move forward
    addSequentialCommand(new DriveToPosition(-590, -590));
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new DriveToPosition(2700, -2700));
    addParallelCommand(new CollectorForwardTimed(1800));
    addSequentialCommand(new DelayCommand(150));

    if (false) {
      // Now we move forward
      addSequentialCommand(new CollectorMiddleForwardTimed(500));
      addParallelCommand(new CollectorForwardTimed(500));

      addSequentialCommand(new DriveToPosition(-400, 400));

      addSequentialCommand(new DriveToPosition(700, 700));
      addSequentialCommand(new DriveToPosition(-1250, 1250, 200));
    } else {
      addSequentialCommand(new DriveToPosition(-700, 700));
      addSequentialCommand(new DelayCommand(150));
      addSequentialCommand(new DriveToPosition(850, 850));
      addSequentialCommand(new DelayCommand(150));
      addSequentialCommand(new DriveToPosition(600, -600));
      addSequentialCommand(new FlywheelRevUp());
      addSequentialCommand(new DelayCommand(250));
      addSequentialCommand(new CollectorMiddleForwardTimed(1500));
      addParallelCommand(new CollectorForwardTimed(500));
    }
  } else {
    addSequentialCommand(new DriveToPosition(-4850, 4850));
    addSequentialCommand(new DriveToPosition(-950, -950));
    addSequentialCommand(new DriveToPosition(4000, -4000, 200));
  }

}
