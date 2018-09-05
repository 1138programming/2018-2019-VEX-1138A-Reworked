#ifndef _COMMANDS_CASCADECONTROL_H_
#define _COMMANDS_CASCADECONTROL_H_

#include "commands/Command.h"

class CascadeControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    CascadeControl();
  private:
    bool cascadeUpButton;
    bool cascadeDownButton;
};

#endif // _COMMANDS_CASCADECONTROL_H_
