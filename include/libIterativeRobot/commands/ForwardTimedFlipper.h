#ifndef _COMMANDS_FORWARDTIMEDFLIPPER_H_
#define _COMMANDS_FORWARDTIMEDFLIPPER_H_

#include "libIterativeRobot/commands/Command.h"

class ForwardTimedFlipper : public libIterativeRobot::Command {
  private:
    int runTime; // Time, in milliseconds, to run
    int startTime; // Starting time of this command
  public:
    bool canRun();
    void initialize();
    void execute();
    bool isFinished();
    void end();
    void interrupted();
    ForwardTimedFlipper(int mSecs);
};

#endif // _COMMANDS_FORWARDTIMEDFLIPPER_H_
