#ifndef _COMMANDS_COMMAND_H_
#define _COMMANDS_COMMAND_H_

#include "main.h"
#include <vector>

class Subsystem;

class Command {
  private:
    std::vector<Subsystem*> subsystemRequirements;
  protected:
    void requires(Subsystem* aSubsystem);
  public:
    int priority = 50; // Commands can only be interrupted by commands with a higher priority
    bool initialized = false;

    std::vector<Subsystem*>& getRequirements();

    virtual bool canRun(); // Whether or not the command can run right now. If false, it is ignored
    virtual void initialize(); // Set up the command for running
    virtual void run(); // Run the command
    virtual bool isFinished(); // Whether or not the command is finished. The run() command is run continuously until thie istrue
    virtual void end(); // Run when command is finished
    virtual void interrupted(); // Run when command was interrupted by one with a higher priority

    // Slightly more advanced features... use at your own risk, as
    // these may have unexpected consequences on the rest of the command system
    virtual bool canBeInterruptedBy(Command* aCommand);

    // ...and finally, the constructor!
    Command();
};

#endif // _COMMANDS_COMMAND_H_
