#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"

#include "libIterativeRobot/commands/FlywheelForward.h"
#include "libIterativeRobot/commands/FlywheelBackwards.h"
#include "libIterativeRobot/commands/CollectorForward.h"
#include "libIterativeRobot/commands/CollectorBackwards.h"
#include "libIterativeRobot/commands/MiddleCollectorForward.h"
#include "libIterativeRobot/commands/MiddleCollectorBackwards.h"
#include "libIterativeRobot/commands/BeaterForward.h"
#include "libIterativeRobot/commands/BeaterBackwards.h"
#include "libIterativeRobot/commands/BaseToggle.h"
#include "libIterativeRobot/commands/BaseSpeedToggle.h"

#include "libIterativeRobot/commands/AutonGroup1.h"

Robot*     Robot::instance  = 0;
Base*      Robot::robotBase = 0;
Collector* Robot::collector = 0;
MiddleCollector* Robot::middleCollector = 0;
Beater*    Robot::beater = 0;
Flywheel*  Robot::flywheel  = 0;

pros::Controller* Robot::mainController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  autonGroup = NULL;
  // Initialize any subsystems
  robotBase = new Base();
  collector = new Collector();
  middleCollector = new MiddleCollector();
  beater = new Beater();
  flywheel  = new Flywheel();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);

  libIterativeRobot::JoystickButton* flywheelForwardButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  flywheelForwardButton->whenPressed(new FlywheelForward());
  libIterativeRobot::JoystickButton* flywheelBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  flywheelBackwardsButton->whenPressed(new FlywheelBackwards());

  libIterativeRobot::JoystickButton* collectorForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  collectorForwardsButton->whileHeld(new CollectorForward());
  libIterativeRobot::JoystickButton* collectorBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  collectorBackwardsButton->whileHeld(new CollectorBackwards());

  libIterativeRobot::JoystickButton* middleCollectorForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  middleCollectorForwardsButton->whileHeld(new MiddleCollectorForward());
  libIterativeRobot::JoystickButton* middleCollectorBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  middleCollectorBackwardsButton->whileHeld(new MiddleCollectorBackwards());

  libIterativeRobot::JoystickButton* beaterForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_B);
  beaterForwardsButton->whileHeld(new BeaterForward());
  libIterativeRobot::JoystickButton* beaterBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);
  beaterBackwardsButton->whileHeld(new BeaterBackwards());

  libIterativeRobot::JoystickButton* toggleButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_Y);
  toggleButton->whenPressed(new BaseToggle());

  libIterativeRobot::JoystickButton* speedToggleButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_A);
  speedToggleButton->whenPressed(new BaseSpeedToggle());
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Default autonInit() function\n");
  if (autonGroup != NULL) {
    delete autonGroup;
  }
  autonGroup = new AutonGroup1();
  autonGroup->run();
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
