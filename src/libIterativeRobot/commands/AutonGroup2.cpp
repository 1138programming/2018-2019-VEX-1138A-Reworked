#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperBackwardTimed.h"

AutonGroup2::AutonGroup2() {
  addSequentialCommand(new FlywheelRevUp());
  addSequentialCommand(new DelayCommand(300));
  addSequentialCommand(new DriveToPosition(2750, 2750, 150));
  addParallelCommand(new CollectorForwardTimed(3000));
  addSequentialCommand(new DriveToPosition(-1000, -1000, 150));
  addSequentialCommand(new DelayCommand(300));
  addSequentialCommand(new DriveToPosition(435, -435, 60));
  addSequentialCommand(new DelayCommand(75));
  addSequentialCommand(new FlipperBackwardTimed(300));
  addSequentialCommand(new DelayCommand(200));
  addSequentialCommand(new DriveToPosition(1200, 1200, 90));
  addSequentialCommand(new DelayCommand(150));
  addSequentialCommand(new FlipperForwardTimed(300));
  addSequentialCommand(new DelayCommand(150));
  addSequentialCommand(new DriveToPosition(-500, -500, 50));
  addSequentialCommand(new DelayCommand(150));
  addSequentialCommand(new DriveToPosition(-1075, 1075, 60));
  addSequentialCommand(new DelayCommand(150));
  addSequentialCommand(new DriveToPosition(600, 600, 50));
  addSequentialCommand(new DelayCommand(1500));
  addSequentialCommand(new CollectorMiddleForwardTimed(1000));
  addParallelCommand(new CollectorForwardTimed(1000));
  //addSequentialCommand(new DriveToPosition(-315, 315));
  //addSequentialCommand(new DriveToPosition(-208, -208));
  /*
  //addSequentialCommand(new DriveToPosition(1250, 1250)); // Forwards one tile
  //addSequentialCommand(new DriveToPosition(-208, 208)); // Rotate 45 degrees left
  //addSequentialCommand(new DriveToPosition(-30, -30)); // Rotate x degrees

  addSequentialCommand(new FlywheelRevUp());
  addParallelCommand(new DriveToPosition(250, -250, 50));
  addSequentialCommand(new CollectorMiddleForwardTimed(500));
  addSequentialCommand(new DelayCommand(150));

  addSequentialCommand(new DriveToPosition(2700, -2700));
  //addSequentialCommand(new DelayCommand(500));
  addSequentialCommand(new DelayCommand(150));

  if (true) { // Two falses for both
    // For going to turn clockwise
    addSequentialCommand(new DriveToPosition(-3400, 3400));
    addSequentialCommand(new DelayCommand(250));

    // Turn and move forwardaz
    addSequentialCommand(new DriveToPosition(-590, -590));
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new DriveToPosition(2700, -2700));
    addParallelCommand(new CollectorForwardTimed(1800));
    addSequentialCommand(new DelayCommand(150));

    if (true) {
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
  */
}
