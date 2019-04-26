#include "libIterativeRobot/commands/Auton/DoubleShot.h"

#include "libIterativeRobot/commands/BaseCommands/DriveToPosition.h"
#include "libIterativeRobot/commands/BaseCommands/DriveLinear.h"
#include "libIterativeRobot/commands/BaseCommands/TurnWithGyro.h"

#include "libIterativeRobot/commands/CollectorCommands/CollectorForwardTimed.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwardsTimed.h"

#include "libIterativeRobot/commands/FlipperCommands/FlipperForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelRevUp.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"

#include "libIterativeRobot/commands/IndexerCommands/IndexerForwardTimed.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerBackwardTimed.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"

DoubleShot::DoubleShot() {
  addSequentialCommand(new DelayCommand(100));
  addSequentialCommand(new IndexerForwardTimed(250));
  addSequentialCommand(new DelayCommand(1000));
  addSequentialCommand(new CollectorForwardTimed(750));
  addParallelCommand(new IndexerForwardTimed(750));
}
