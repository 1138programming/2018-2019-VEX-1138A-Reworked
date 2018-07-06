#ifndef _EVENTS_JOYSTICKBUTTON_H_
#define _EVENTS_JOYSTICKBUTTON_H_

#include "main.h"
#include "events/EventListener.h"
#include "commands/Command.h"

enum Joysticks {
  MainJoystick=1,
  PartnerJoystick,
};
enum Buttons {
  // Button group 5
  Btn5U,
  Btn5D,

  // Button group 6
  Btn6U,
  Btn6D,

  // Button group 7
  Btn7U,
  Btn7D,
  Btn7L,
  Btn7R,

  // Button group 8
  Btn8U,
  Btn8D,
  Btn8L,
  Btn8R,
};


class JoystickButton : public EventListener {
  private:
    char joystickToCheck;
    char buttonGroup;
    char button;
    bool lastState = false;
    Command* pressedCommand = NULL;
    Command* heldCommand = NULL;
    Command* depressedCommand = NULL;
    Command* releasedCommand = NULL;
  protected:
    virtual void checkConditions();
  public:
    JoystickButton(Joysticks joystick, Buttons button);
    void whenPressed(Command* pressedCommand);
    void whileHeld(Command* heldCommand);
    void whenDepressed(Command* depressedCommand);
    void whileReleased(Command* releasedCommand);
};

#endif // _EVENTS_JOYSTICKBUTTON_H_
