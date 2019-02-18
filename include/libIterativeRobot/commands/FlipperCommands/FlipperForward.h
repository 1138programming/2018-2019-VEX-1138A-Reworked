#ifndef _COMMANDS_FLIPPERFORWARD_H_
#define _COMMANDS_FLIPPERFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperForward : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperForward();
};

#endif // _COMMANDS_FLIPPERFORWARD_H_
