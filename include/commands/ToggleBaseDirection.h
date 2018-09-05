#ifndef _COMMANDS_TOGGLEBASEDIRECTION_H_
#define _COMMANDS_TOGGLEBASEDIRECTION_H_

#include "commands/Command.h"

class ToggleBaseDirection: public Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ToggleBaseDirection();
  private:
    bool baseToggleButton;
};

#endif // _COMMANDS_TOGGLEBASEDIRECTION_H_
