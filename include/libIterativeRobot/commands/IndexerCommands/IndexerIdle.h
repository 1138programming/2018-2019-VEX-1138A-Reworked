#ifndef _COMMANDS_INDEXERIDLE_H_
#define _COMMANDS_INDEXERIDLE_H_

#include "libIterativeRobot/commands/Command.h"

class IndexerIdle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    IndexerIdle();
};

#endif // _COMMANDS_INDEXERIDLE_H_
