#ifndef _COMMANDS_EXAMPLEWAITCOMMAND_H_
#define _COMMANDS_EXAMPLEWAITCOMMAND_H_

#include "commands/Command.h"

class ExampleWaitCommand : public Command {
  private:
    unsigned int startTime = 0;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ExampleWaitCommand();
};

#endif // _COMMANDS_EXAMPLEWAITCOMMAND_H_
