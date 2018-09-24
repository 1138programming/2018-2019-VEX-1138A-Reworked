#ifndef _EVENTS_JOYSTICKBUTTON_H_
#define _EVENTS_JOYSTICKBUTTON_H_

#include "main.h"
#include "events/EventListener.h"
#include "commands/Command.h"

// An enum for the main or partner joystick
enum Joysticks {
  MainJoystick=1,
  PartnerJoystick,
};

// An enum for every button on the controller
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
    char joystickToCheck; // Either the main or partner joystick
    char buttonGroup; // Which button group the button is in
    char button; // Which button in the button group to check
    bool lastState = false; // Keeps track of the last state of the button being checked
    Command* pressedCommand = NULL; // Command or command group run when the button is pressed
    Command* heldCommand = NULL; // Command or command group run while the button is held down
    Command* depressedCommand = NULL; // Command or command group run when the button is let go of
    Command* releasedCommand = NULL; // Command or command group run while the button is not being held down
  protected:
    virtual void checkConditions(); // Checks the button's conditions and decides which, if any, command to run
  public:
    JoystickButton(Joysticks joystick, Buttons button);
    void whenPressed(Command* pressedCommand); // Sets pressedCommand
    void whileHeld(Command* heldCommand); // Sets heldCommand
    void whenDepressed(Command* depressedCommand); // Sets depressedCommand
    void whileReleased(Command* releasedCommand); // Sets releasedCommand
};

#endif // _EVENTS_JOYSTICKBUTTON_H_
