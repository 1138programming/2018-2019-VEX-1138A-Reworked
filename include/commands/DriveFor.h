#ifndef _COMMANDS_DRIVEFOR_H_
#define _COMMANDS_DRIVEFOR_H_

#include "commands/Command.h"

class DriveFor: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveFor(unsigned int duration, int leftSpeed, int rightSpeed);
  private:
    unsigned int duration;
    unsigned int startTime;
    int leftSpeed;
    int rightSpeed;
};

#endif // _COMMANDS_EXAMPLECOMMAND_H_
