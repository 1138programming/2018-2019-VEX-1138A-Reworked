#ifndef _COMMANDS_ULTRASONICIDLE_H_
#define _COMMANDS_ULTRASONICIDLE_H_

#include "libIterativeRobot/commands/Command.h"

class UltrasonicIdle : public libIterativeRobot::Command {
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    UltrasonicIdle();
};

#endif // _COMMANDS_ULTRASONICIDLE_H_
