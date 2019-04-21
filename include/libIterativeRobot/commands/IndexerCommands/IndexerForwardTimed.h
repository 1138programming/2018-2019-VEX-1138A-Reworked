#ifndef _COMMANDS_INDEXERFORWARDTIMED_H_
#define _COMMANDS_INDEXERFORWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class IndexerForwardTimed : public libIterativeRobot::Command {
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
    IndexerForwardTimed(int mSecs);
};

#endif // _COMMANDS_INDEXERFORWARDTIMED_H_
