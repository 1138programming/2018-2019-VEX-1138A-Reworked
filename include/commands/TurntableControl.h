#ifndef _COMMANDS_TURNTABLECONTROL_H_
#define _COMMANDS_TURNTABLECONTROL_H_

#include "commands/Command.h"

class TurntableControl: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    TurntableControl();
  private:
    bool turntableUpButton;
    bool turntableDownButton;
};

#endif // _COMMANDS_TURNTABLECONTROL_H_
