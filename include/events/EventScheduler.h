#ifndef _EVENTS_EVENTSCHEDULER_H_
#define _EVENTS_EVENTSCHEDULER_H_

#include "main.h"
#include "events/EventListener.h"
#include "commands/Command.h"
#include "subsystems/Subsystem.h"
#include <vector>

class EventScheduler {
  private:
    static EventScheduler* instance;
    EventScheduler();
    std::vector<Subsystem*> subsystems;
    std::vector<EventListener*> eventListeners;
    std::vector<Command*> commandQueue;
  public:
    const static int millisecondTimeout = 25; // Maximum time to run event listeners
    static EventScheduler* getInstance(); // Return the singleton instance of me
    void update();
    void addEventListener(EventListener* eventListener);
    void addCommand(Command* commandToRun);
    void trackSubsystem(Subsystem* aSubsystem);
    bool commandInQueue(Command* aCommand);
};

#endif // _EVENTS_EVENTSCHEDULER_H_
