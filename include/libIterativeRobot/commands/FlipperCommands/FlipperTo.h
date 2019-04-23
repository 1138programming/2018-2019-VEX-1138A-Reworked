#ifndef _COMMANDS_FLIPPERTO_H_
#define _COMMANDS_FLIPPERTO_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperTo : public libIterativeRobot::Command {
  private:
    int target;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperTo(int target);
};

#endif // _COMMANDS_FLIPPERTO_H_
