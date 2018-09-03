#ifndef _COMMANDS_INTAKECONTROL_H_
#define _COMMANDS_INTAKECONTROL_H_

#include "commands/Command.h"

class IntakeControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    IntakeControl();
  private:
    bool intakeUpButton;
    bool intakeDownButton;
};

#endif // _COMMANDS_INTAKECONTROL_H_
