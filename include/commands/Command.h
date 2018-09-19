#ifndef _COMMANDS_COMMAND_H_
#define _COMMANDS_COMMAND_H_

#include "main.h"
#include <vector>
#include "subsystems/Subsystem.h"
//#include "events/EventScheduler.h"
//#include "commands/CommandGroup.h"

enum Status {
  Idle = 0,
  Running,
  Finished,
  Interrupted
};

class Command {
  private:
    std::vector<Subsystem*> subsystemRequirements;
  protected:
    void requires(Subsystem* aSubsystem);
  public:
    static const int DefaultCommandPriority = 0;

    int priority = 50; // Commands can only be interrupted by commands with a higher priority
    bool initialized = false;
    Status status = Idle;

    std::vector<Subsystem*>& getRequirements();

    //void run();

    virtual bool canRun(); // Whether or not the command can run right now. If false, it is ignored
    virtual void initialize(); // Set up the command for running
    virtual void execute(); // Run the command
    virtual bool isFinished(); // Whether or not the command is finished. The run() command is run continuously until thie istrue
    virtual void end(); // Run when command is finished
    virtual void interrupted(); // Run when command was interrupted by one with a higher priority

    // Slightly more advanced features... use at your own risk, as
    // these may have unexpected consequences on the rest of the command system
    // See comment in cpp file, may be re-added later
    //virtual bool canBeInterruptedBy(Command* aCommand);

    virtual void run(); // Run this command. May be called anywhere.
    virtual void stop(); // Stop this command while it is running. May be called anywhere.

    virtual void printSomething();

    // ...and finally, the constructor!
    Command();
};

#endif // _COMMANDS_COMMAND_H_
