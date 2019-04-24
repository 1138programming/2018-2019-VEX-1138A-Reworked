#ifndef _COMMANDS_COLLECTORANDINDEXER_H_
#define _COMMANDS_COLLECTORANDINDEXER_H_

#include "libIterativeRobot/commands/Command.h"

class CollectorAndIndexer : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CollectorAndIndexer();
};

#endif // _COMMANDS_COLLECTORANDINDEXER_H_
