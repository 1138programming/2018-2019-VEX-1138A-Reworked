#ifndef _COMMANDS_COMMANDGROUP_H_
#define _COMMANDS_COMMANDGROUP_H_

#include "commands/Command.h"
#include "main.h"
#include <vector>

class CommandGroup : public Command {
  private:
    std::vector<std::vector<Command*>> commands;
    std::vector<std::vector<Subsystem*>> requirements;
    std::vector<std::vector<bool>> added;
    size_t sequentialIndex = 0;
  public:
    //int priority = 50; // Commands can only be interrupted by commands with a higher priority
    Status status;

    std::vector<Subsystem*>& getRequirements();

    bool canRun();
    void initialize(); // Set up the command for running
    void execute(); // Run the command
    bool isFinished(); // Whether or not the command is finished. The run() command is run continuously until thie istrue
    void end();
    void interrupted();
    virtual void addSequentialCommand(Command* aCommand);
    virtual void addParallelCommand(Command* aCommand);

    void run(); // Run this command group. May be called anywhere.
    void stop(); // Stop this command group while it is running. May be called anywhere.

    CommandGroup(); // How about we only have them override the Constructor...
};

#endif // _COMMANDS_COMMANDGROUP_H_
