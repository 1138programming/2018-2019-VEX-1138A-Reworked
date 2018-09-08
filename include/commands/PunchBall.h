#ifndef _COMMANDS_PUNCHBALL_H_
#define _COMMANDS_PUNCHBALL_H_

#include "commands/Command.h"

class PunchBall: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    PunchBall();
  private:
    unsigned int startTime = 0;
    unsigned int duration = 2000;
};

#endif // _COMMANDS_PUNCHBALL_H_
