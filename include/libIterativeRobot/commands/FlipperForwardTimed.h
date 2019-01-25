#ifndef _COMMANDS_FLIPPERFORWARDTIMED_H_
#define _COMMANDS_FLIPPERFORWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class FlipperForwardTimed : public libIterativeRobot::Command {
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
    FlipperForwardTimed(int speed, int mSecs);
};

#endif // _COMMANDS_FLIPPERFORWARDTIMED_H_
