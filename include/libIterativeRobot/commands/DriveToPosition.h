#ifndef _COMMANDS_DRIVETOPOSITION_H_
#define _COMMANDS_DRIVETOPOSITION_H_

#include "libIterativeRobot/commands/Command.h"

class DriveToPosition : public libIterativeRobot::Command {
  private:
    int leftTarget;
    int rightTarget;
    int motorSpeed;
    int mV;

    int endTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    //DriveToPosition(int leftTarget, int rightTarget, int motorSpeed, int mV);
    //DriveToPosition(int leftTarget, int rightTarget);
    DriveToPosition(int leftTarget, int rightTarget, int motorSpeed = 0, int mV = 12000);
};

#endif // _COMMANDS_DRIVETOPOSITION_H_
