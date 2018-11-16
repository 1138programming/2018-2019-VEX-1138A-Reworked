#ifndef _COMMANDS_TURNWITHGYRO_H_
#define _COMMANDS_TURNWITHGYRO_H_

#include "libIterativeRobot/commands/Command.h"

class TurnWithGyro : public libIterativeRobot::Command {
  private:
    int degrees;
    int motorSpeed;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    TurnWithGyro(int turnDegrees, int motorSpeed);
    TurnWithGyro(int turnDegrees);
};

#endif // _COMMANDS_TURNWITHGYRO_H_
