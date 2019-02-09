#ifndef _COMMANDS_FLIPPERBACKWARDSTIMED_H_
#define _COMMANDS_FLIPPERBACKWARDSTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperBackwardsTimed : public libIterativeRobot::Command {
  private:
    int speed; // Speed for the flipper to run at
    int runTime; // Time, in milliseconds, to run
    int startTime; // Starting time of this command
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    FlipperBackwardsTimed(int speed, int mSecs);
};

#endif // _COMMANDS_FLIPPERBACKWARDSTIMED_H_
