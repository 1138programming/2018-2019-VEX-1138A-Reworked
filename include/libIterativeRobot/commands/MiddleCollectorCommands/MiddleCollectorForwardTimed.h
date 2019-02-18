#ifndef _COMMANDS_MIDDLECOLLECTORFORWARDTIMED_H_
#define _COMMANDS_MIDDLECOLLECTORFORWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class MiddleCollectorForwardTimed : public libIterativeRobot::Command {
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
    MiddleCollectorForwardTimed(int mSecs);
};

#endif // _COMMANDS_MIDDLECOLLECTORFORWARDTIMED_H_
