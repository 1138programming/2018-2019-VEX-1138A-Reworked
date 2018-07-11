#ifndef _COMMANDS_COMMANDGROUP_H_
#define _COMMANDS_COMMANDGROUP_H_

#include "main.h"
#include "commands/Command.h"
#include <vector>

class CommandGroup : public Command {
  private:
    std::vector<std::vector<Command*>> commands;
    size_t commandIndex = 0;
  public:
    int priority = 50; // Commands can only be interrupted by commands with a higher priority

    void initialize(); // Set up the command for running
    void execute(); // Run the command
    bool isFinished(); // Whether or not the command is finished. The run() command is run continuously until thie istrue
    virtual void addSequentialCommand(Command* aCommand);
    virtual void addParallelCommand(Command* aCommand);
    CommandGroup(); // How about we only have them override the Constructor...
};

#endif // _COMMANDS_COMMANDGROUP_H_
