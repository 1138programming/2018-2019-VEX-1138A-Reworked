#ifndef _COMMANDS_DRIVELINEARLY_H_
#define _COMMANDS_DRIVELINEARLY_H_

#include "libIterativeRobot/commands/Command.h"

class DriveLinear : public libIterativeRobot::Command {
  private:
    double target;
    double motorSpeed;

    int endTime;
    int startTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveLinear(int target, int motorSpeed);
    DriveLinear(int target);
};

#endif // _COMMANDS_DriveLinearly_H_
