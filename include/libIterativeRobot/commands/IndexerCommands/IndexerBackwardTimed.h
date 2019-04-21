#ifndef _COMMANDS_INDEXERBACKWARDTIMED_H_
#define _COMMANDS_INDEXERBACKWARDTIMED_H_

#include "libIterativeRobot/commands/Command.h"

class IndexerBackwardTimed : public libIterativeRobot::Command {
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
    IndexerBackwardTimed(int mSecs);
};

#endif // _COMMANDS_INDEXERBACKWARDTIMED_H_
