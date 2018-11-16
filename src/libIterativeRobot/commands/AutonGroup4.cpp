#include "libIterativeRobot/commands/AutonGroup4.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"

AutonGroup4::AutonGroup4() {
  // Bottom and middle flag
    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new DriveToPosition(1100, -1100));
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new CollectorMiddleForwardTimed(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(2800, -2800));
    addSequentialCommand(new DelayCommand(150));


    addSequentialCommand(new DriveToPosition(-3150, 3150));

}
