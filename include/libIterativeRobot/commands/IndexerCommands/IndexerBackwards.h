#ifndef _COMMANDS_INDEXERBACKWARDS_H_
#define _COMMANDS_INDEXERBACKWARDS_H_

#include "libIterativeRobot/commands/Command.h"

class IndexerBackwards : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    IndexerBackwards();
};

#endif // _COMMANDS_INDEXERBACKWARDS_H_
