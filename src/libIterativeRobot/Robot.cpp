#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

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
#include "libIterativeRobot/commands/AutonGroup2.h"
#include "libIterativeRobot/commands/AutonGroup3.h"
#include "libIterativeRobot/commands/AutonGroup4.h"

Robot*     Robot::instance  = 0;
Base*      Robot::robotBase = 0;
Collector* Robot::collector = 0;
MiddleCollector* Robot::middleCollector = 0;
Beater*    Robot::beater = 0;
Flywheel*  Robot::flywheel  = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  robotBase = new Base();
  collector = new Collector();
  middleCollector = new MiddleCollector();
  beater = new Beater();
  flywheel  = new Flywheel();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  libIterativeRobot::JoystickButton* flywheelForwardButton = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_UP);
  flywheelForwardButton->whenPressed(new FlywheelForward());
  libIterativeRobot::JoystickButton* flywheelBackwardsButton = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_DOWN);
  flywheelBackwardsButton->whenPressed(new FlywheelBackwards());

  libIterativeRobot::JoystickButton* collectorForwardsButton = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_L2);
  collectorForwardsButton->whileHeld(new CollectorForward());
  libIterativeRobot::JoystickButton* collectorBackwardsButton = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_L1);
  collectorBackwardsButton->whileHeld(new CollectorBackwards());

  libIterativeRobot::JoystickButton* middleCollectorForwardsButton = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_R2);
  middleCollectorForwardsButton->whileHeld(new MiddleCollectorForward());
  libIterativeRobot::JoystickButton* middleCollectorBackwardsButton = new libIterativeRobot::JoystickButton(partnerController, pros::E_CONTROLLER_DIGITAL_R1);
  middleCollectorBackwardsButton->whileHeld(new MiddleCollectorBackwards());

  libIterativeRobot::JoystickButton* beaterForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_B);
  beaterForwardsButton->whileHeld(new BeaterForward());
  libIterativeRobot::JoystickButton* beaterBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);
  beaterBackwardsButton->whileHeld(new BeaterBackwards());

  libIterativeRobot::JoystickButton* toggleButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_Y);
  toggleButton->whenPressed(new BaseToggle());

  libIterativeRobot::JoystickButton* speedToggleButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_A);
  speedToggleButton->whenPressed(new BaseSpeedToggle());

  autonGroup = NULL;
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  libIterativeRobot::EventScheduler::getInstance()->initialize();

  // Make the auton command group

  // Delete the old one, if it exists
  if (autonGroup != NULL) {
    delete autonGroup;
    autonGroup = NULL;
  }

  autonChooser->uninit(); // Remove the auton chooser before starting auton
  switch (autonChooser->getAutonChoice()) { // ?
    case 0:
      autonGroup = new AutonGroup1();
      break;
    case 1:
      autonGroup = new AutonGroup2();
      break;
    case 2:
      autonGroup = new AutonGroup3();
      break;
    case 3:
      autonGroup = new AutonGroup4();
      break;
  }
  autonGroup->run();
}

void Robot::autonPeriodic() {
  libIterativeRobot::EventScheduler::getInstance()->update();
  //Motor::periodicUpdate();
  //PIDController::loopAll();
}

void Robot::teleopInit() {
  libIterativeRobot::EventScheduler::getInstance()->initialize();

  autonChooser->init();
  printf("Default teleopInit() function\n");
}

void Robot::teleopPeriodic() {
  printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  //Motor::periodicUpdate();
  //PIDController::loopAll();
}

void Robot::disabledInit() {
  autonChooser->uninit(); // Can't update display during disabled
  printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}
