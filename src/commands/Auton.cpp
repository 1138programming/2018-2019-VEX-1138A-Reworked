#include "commands/Auton.h"
#include "commands/PunchBall.h"
#include "commands/DriveFor.h"

Auton::Auton() {
  addSequentialCommand(new PunchBall());
  //addSequentialCommand(new DriveFor(1000, 127, 127));
}
