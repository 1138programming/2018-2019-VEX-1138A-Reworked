#ifndef _COMMANDS_BRAKEBASEFOR_H_
#define _COMMANDS_BRAKEBASEFOR_H_

#include "libIterativeRobot/commands/Command.h"
#include "abstractBaseClasses/PIDController.h"

class ToggleBrake : public libIterativeRobot::Command {
  private:
    bool brake = false;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ToggleBrake(bool brake);
};

#endif // _COMMANDS_BRAKEBASEFOR_H_
