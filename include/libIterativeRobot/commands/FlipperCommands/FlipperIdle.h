#ifndef _COMMANDS_FLIPPERIDLE_H_
#define _COMMANDS_FLIPPERIDLE_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperIdle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperIdle();
};

#endif // _COMMANDS_FLIPPERIDLE_H_
