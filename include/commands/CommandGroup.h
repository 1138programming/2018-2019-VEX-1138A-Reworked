#ifndef _COMMANDS_COMMANDGROUP_H_
#define _COMMANDS_COMMANDGROUP_H_

#include "main.h"
#include "commands/Command.h"
#include <vector>

class CommandGroup : public Command {
  private:
    std::vector<std::vector<Command*>> commands;
  public:
    int priority = 50; // Commands can only be interrupted by commands with a higher priority

    virtual bool canRun(); // Whether or not the command can run right now. If false, it is ignored
    virtual void initialize(); // Set up the command for running
    virtual void run(); // Run the command
    virtual bool isFinished(); // Whether or not the command is finished. The run() command is run continuously until thie istrue
    virtual void end(); // Run when command is finished
    virtual void interrupted(); // Run when command was interrupted by one with a higher priority
    void addCommand(Command* aCommand);
    void addParallelCommand(Command* aCommand);
    CommandGroup();
};

#endif // _COMMANDS_COMMANDGROUP_H_
