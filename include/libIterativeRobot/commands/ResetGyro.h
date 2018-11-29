#ifndef _COMMANDS_RESETGYRO_H_
#define _COMMANDS_RESETGYRO_H_

#include "libIterativeRobot/commands/Command.h"
#include "abstractBaseClasses/PIDController.h"

class ResetGyro : public libIterativeRobot::Command {
  private:
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ResetGyro();
};

#endif // _COMMANDS_RESETGYRO_H_
