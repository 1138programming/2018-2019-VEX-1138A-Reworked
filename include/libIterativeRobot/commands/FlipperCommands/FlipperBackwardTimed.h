#ifndef _COMMANDS_FLIPPERBACKWARDTIMED_H_
#define _COMMANDS_FLIPPERBACKWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperBackwardTimed : public libIterativeRobot::Command {
  private:
    int runTime; // Time, in milliseconds, to run
    int startTime; // Starting time of this command
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperBackwardTimed(int mSecs);
};

#endif // _COMMANDS_FLIPPERBACKWARDTIMED_H_
