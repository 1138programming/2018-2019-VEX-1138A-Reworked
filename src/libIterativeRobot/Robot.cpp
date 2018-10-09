#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"

#include "libIterativeRobot/commands/FlywheelForward.h"
#include "libIterativeRobot/commands/FlywheelBackwards.h"
#include "libIterativeRobot/commands/CollectorForward.h"
#include "libIterativeRobot/commands/CollectorBackwards.h"

Robot*     Robot::instance  = 0;
Base*      Robot::robotBase = 0;
Collector* Robot::collector = 0;
Flywheel*  Robot::flywheel  = 0;

pros::Controller* Robot::mainController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  robotBase = new Base();
  collector = new Collector();
  flywheel  = new Flywheel();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);

  libIterativeRobot::JoystickButton* flywheelForwardButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  flywheelForwardButton->whileHeld(new FlywheelForward());
  libIterativeRobot::JoystickButton* flywheelBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  flywheelBackwardsButton->whileHeld(new FlywheelBackwards());

  libIterativeRobot::JoystickButton* collectorForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  collectorForwardsButton->whileHeld(new CollectorForward());
  libIterativeRobot::JoystickButton* collectorBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  collectorBackwardsButton->whileHeld(new CollectorBackwards());
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");
}

void Robot::autonPeriodic() {
  // printf("Default autonPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
}

void Robot::teleopInit() {
  printf("Default teleopInit() function\n");
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
