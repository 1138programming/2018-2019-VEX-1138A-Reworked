#ifndef _COMMANDS_MIDDLECOLLECTORBACKWARDTIMED_H_
#define _COMMANDS_MIDDLECOLLECTORBACKWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class MiddleCollectorBackwardTimed : public libIterativeRobot::Command {
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
    MiddleCollectorBackwardTimed(int mSecs);
};

#endif // _COMMANDS_MIDDLECOLLECTORBACKWARDTIMED_H_
