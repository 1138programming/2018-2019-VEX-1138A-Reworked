#ifndef _COMMANDS_MOVEBASETO_H_
#define _COMMANDS_MOVEBASETO_H_

#include "libIterativeRobot/commands/Command.h"

class MoveBaseTo: public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    MoveBaseTo(int leftTarget, int rightTarget, int maxSpeed = KMaxMotorSpeed, int timeout = 3000, bool absolute = false);
  private:
    int leftTarget = 0;
    int rightTarget = 0;
    int maxSpeed = KMaxMotorSpeed;
    bool absolute = false;
    int startTime = 0;
    int timeout = 0;
};

#endif // _COMMANDS_MOVEBASETO_H_
