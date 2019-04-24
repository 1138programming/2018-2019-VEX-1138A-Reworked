#ifndef _COMMANDS_SHOOTANDLOAD_H_
#define _COMMANDS_SHOOTANDLOAD_H_

#include "libIterativeRobot/commands/Command.h"

class ShootAndLoad : public libIterativeRobot::Command {
  private:
    int startTime;
    int runTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ShootAndLoad();
};

#endif // _COMMANDS_SHOOTANDLOAD_H_
