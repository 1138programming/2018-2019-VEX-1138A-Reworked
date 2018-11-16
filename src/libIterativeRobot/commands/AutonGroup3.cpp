#include "libIterativeRobot/commands/AutonGroup3.h"
#include "libIterativeRobot/commands/DriveToPosition.h"
#include "libIterativeRobot/commands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/DelayCommand.h"
#include "libIterativeRobot/commands/CollectorMiddleForwardTimed.h"
#include "libIterativeRobot/commands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/TurnWithGyro.h"

AutonGroup3::AutonGroup3() {
    addSequentialCommand(new FlywheelRevUp());
    addSequentialCommand(new CollectorMiddleForwardTimed(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(3050, -3050));
    //addSequentialCommand(new DelayCommand(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(-5050, 5050)); // 5050 for BLUE, 4850 for RED

#ifdef USE_GYRO
    addSequentialCommand(new TurnWithGyro(900)); // - for BLUE
#else
    addSequentialCommand(new DriveToPosition(-760, -760)); // Both negative for BLUE
#endif

    addSequentialCommand(new DriveToPosition(5950, -5950, 200)); // Red is 6250, blue is 5950
}
