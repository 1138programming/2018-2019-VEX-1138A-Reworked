#ifndef _COMMANDS_DRIVELINEARLY_H_
#define _COMMANDS_DRIVELINEARLY_H_

#include "libIterativeRobot/commands/Command.h"

class DriveLinear : public libIterativeRobot::Command {
  private:
    int leftTarget;
    int rightTarget;
    int motorSpeed;

    int endTime;
    int startTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    DriveLinear(int target);
    DriveLinear(int leftTarget, int rightTarget);
    //DriveLinear(int leftTarget, int rightTarget, double maxAccel, double maxVel);
};

#endif // _COMMANDS_DriveLinearly_H_
