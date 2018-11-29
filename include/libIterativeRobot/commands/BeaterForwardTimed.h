#ifndef _COMMANDS_BEATERFORWARDTIMED_H_
#define _COMMANDS_BEATERFORWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class BeaterForwardTimed : public libIterativeRobot::Command {
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
    BeaterForwardTimed(int mSecs);
};

#endif // _COMMANDS_BEATERFORWARDTIMED_H_
