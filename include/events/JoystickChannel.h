#ifndef _EVENTS_JOYSTICKCHANNEL_H_
#define _EVENTS_JOYSTICKCHANNEL_H_

#include "main.h"
#include "events/EventListener.h"
#include "commands/Command.h"
#include "events/JoystickButton.h"

// Enum for joystick channels
enum Channels {
  ChRightY=1,
  ChRightX,
  ChLeftY,
  ChLeftX,
};


class JoystickChannel : public EventListener {
  private:
    char joystickToCheck; // Either the main or partner joystick
    int channel; // The channel to check
    int threshold = kDefaultThreshold; // The treshold for the joystick value
    Command* pastThresholdCommand = NULL; // Command or command group run if the joystick value is past the threshold
  protected:
    virtual void checkConditions();
  public:
    static const int kDefaultThreshold = 10; // Default threshold
    JoystickChannel(Joysticks joystick, Channels channel);
    void whilePastThreshold(Command* pastThresholdCommand, int threshold = kDefaultThreshold);
};

#endif // _EVENTS_JOYSTICKCHANNEL_H_
