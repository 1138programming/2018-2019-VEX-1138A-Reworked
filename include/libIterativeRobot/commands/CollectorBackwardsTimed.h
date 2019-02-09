#ifndef _COMMANDS_COLLECTORBACKWARDSTIMED_H_
#define _COMMANDS_COLLECTORBACKWARDSTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorBackwardsTimed : public libIterativeRobot::Command {
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
    CollectorBackwardsTimed(int mSecs);
};

#endif // _COMMANDS_COLLECTORBACKWARDSTIMED_H_
