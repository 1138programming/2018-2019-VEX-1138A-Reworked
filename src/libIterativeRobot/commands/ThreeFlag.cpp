#include "libIterativeRobot/commands/ThreeFlag.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/TurnWithGyro.h"

ThreeFlag::ThreeFlag() {
    addSequentialCommand(new FlywheelRevUp());
    addParallelCommand(new CollectorForwardTimed(1500));
    addParallelCommand(new DriveToPosition(3750, -3750)); // Forward for 4450
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new CollectorForwardTimed(150));
    addParallelCommand(new CollectorMiddleForwardTimed(250));
    addParallelCommand(new DriveToPosition(250, -250));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(-4350, 4350)); // Back to starting point
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new DriveToPosition(250, -250));
    addSequentialCommand(new DelayCommand(150));

#ifdef USE_GYRO
    addSequentialCommand(new TurnWithGyro(-900)); // 900 for red, -900 for blue
#else
    addSequentialCommand(new DriveToPosition(680, 680)); // Rotate counterclockwise? // - for red
#endif
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new CollectorMiddleForwardTimed(500));
    addSequentialCommand(new DriveToPosition(1800, -1800));
    addSequentialCommand(new DelayCommand(150));
    addSequentialCommand(new CollectorMiddleForwardTimed(1500));

    addSequentialCommand(new DriveToPosition(-3159, 3150));

// #ifdef USE_GYRO
//     addSequentialCommand(new TurnWithGyro(900)); // -90 for red, 90 for blue
// #else
//     addSequentialCommand(new DriveToPosition(-760, -760)); // Both positive for RED
// #endif
//     addSequentialCommand(new DriveToPosition(6750, -6750, 200));
}
