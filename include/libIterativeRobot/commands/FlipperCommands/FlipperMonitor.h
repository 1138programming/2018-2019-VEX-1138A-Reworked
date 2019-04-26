#ifndef _COMMANDS_FLIPPERMONITOR_H_
#define _COMMANDS_FLIPPERMONITOR_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperMonitor : public libIterativeRobot::Command {
  private:
    int lastTime = 0;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperMonitor();
};

#endif // _COMMANDS_FLIPPERMONITOR_H_
