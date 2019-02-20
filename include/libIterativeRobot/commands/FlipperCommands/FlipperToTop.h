#ifndef _COMMANDS_FLIPPERTOTOP_H_
#define _COMMANDS_FLIPPERTOTOP_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperToTop : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperToTop();
};

#endif // _COMMANDS_FLIPPERTOTOP_H_
