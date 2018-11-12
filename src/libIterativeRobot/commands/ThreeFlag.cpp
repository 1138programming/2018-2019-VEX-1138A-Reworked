#include "libIterativeRobot/commands/ThreeFlag.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"

ThreeFlag::ThreeFlag() {
    //addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new CollectorForwardTimed(1500));
    addParallelCommand(new DriveToPosition(3750, -3750)); // Forward for 4450

    addSequentialCommand(new CollectorForwardTimed(150));
    addParallelCommand(new CollectorMiddleForwardTimed(500));
    addParallelCommand(new DriveToPosition(250, -250));

    addSequentialCommand(new DriveToPosition(-4250, 4250)); // Back to starting point
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new DriveToPosition(250, -250));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(680, 680)); // Rotate counterclockwise? // - for red

    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new CollectorMiddleForwardTimed(500));
    addSequentialCommand(new DriveToPosition(1800, -1800));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(1250, -1250));
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new CollectorMiddleForwardTimed(1500));

    addSequentialCommand(new DriveToPosition(-4850, 4850));
    addSequentialCommand(new DriveToPosition(-760, -760)); // Both positive for RED
    addSequentialCommand(new DriveToPosition(6750, -6750, 200));
}
