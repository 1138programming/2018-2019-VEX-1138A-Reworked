#ifndef _COMMANDS_FLIPPERBACKWARDS_H_
#define _COMMANDS_FLIPPERBACKWARDS_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperBackwards : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperBackwards();
};

#endif // _COMMANDS_FLIPPERBACKWARDS_H_
