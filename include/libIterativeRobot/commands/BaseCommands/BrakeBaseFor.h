#ifndef _COMMANDS_BRAKEBASEFOR_H_
#define _COMMANDS_BRAKEBASEFOR_H_

#include "libIterativeRobot/commands/Command.h"
#include "abstractBaseClasses/PIDController.h"

class BrakeBaseFor : public libIterativeRobot::Command {
  private:
    int timeToRun;
    int startTime;
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    BrakeBaseFor(int timeToRun);
};

#endif // _COMMANDS_BRAKEBASEFOR_H_
