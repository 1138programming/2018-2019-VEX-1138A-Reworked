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

    addSequentialCommand(new DriveToPosition(3650, 3650));
    //addSequentialCommand(new DelayCommand(500));
    addSequentialCommand(new DelayCommand(150));

    addSequentialCommand(new DriveToPosition(-5050, -5050)); // 5050 for BLUE, 4850 for RED

    addSequentialCommand(new TurnWithGyro(-930)); // - for BLUE

    addSequentialCommand(new DriveToPosition(4250, 4250, 200)); // Red is 6250, blue is 5950
}
