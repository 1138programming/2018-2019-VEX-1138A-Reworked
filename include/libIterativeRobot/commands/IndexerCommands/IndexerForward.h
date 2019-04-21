#ifndef _COMMANDS_INDEXERFORWARD_H_
#define _COMMANDS_INDEXERFORWARD_H_

#include "libIterativeRobot/commands/Command.h"

class IndexerForward : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    IndexerForward();
};

#endif // _COMMANDS_INDEXERFORWARD_H_
