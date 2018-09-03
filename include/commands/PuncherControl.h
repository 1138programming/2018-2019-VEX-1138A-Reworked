#ifndef _COMMANDS_PUNCHERCONTROL_H_
#define _COMMANDS_PUNCHERCONTROL_H_

#include "commands/Command.h"

class PuncherControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    PuncherControl();
  private:
    bool puncherUpButton;
    bool puncherDownButton;
};

#endif // _COMMANDS_PUNCHERCONTROL_H_
