#include "Robot.h"
#include "events/EventScheduler.h"
#include "events/JoystickButton.h"

#include "commands/DriveWithJoy.h"

Robot* Robot::instance = 0;
Base* Robot::base = 0;
Intake* Robot::intake = 0;
Lift* Robot::lift = 0;
Puncher* Robot::puncher = 0;
Turntable* Robot::turntable = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  base = Base::getInstance();
  intake = Intake::getInstance();
  lift = Lift::getInstance();
  puncher = Puncher::getInstance();
  turntable = Turntable::getInstance();

  // Initialize any actions/commands needed
  //JoystickButton* test = new JoystickButton(MainJoystick, Btn5U);
  //test->whenPressed(new ExampleCommand());
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  //printf("Default autonInit() function\n");
}

void Robot::autonPeriodic() {
  //printf("Default autonPeriodic() function\n");
  EventScheduler::getInstance()->update();
}

void Robot::teleopInit() {
  //printf("Default teleopInit() function\n");
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
    EventScheduler::getInstance()->update();
}

void Robot::disabledInit() {
  //printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function");
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
