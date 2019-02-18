#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelForward.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorForward.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwards.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForward.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorBackwards.h"
#include "libIterativeRobot/commands/MiddleCollectorCommands/MiddleCollectorForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperForward.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwards.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"
#include "libIterativeRobot/commands/BaseCommands/BaseToggle.h"
#include "libIterativeRobot/commands/BaseCommands/BaseSpeedToggle.h"

#include "libIterativeRobot/commands/Auton/Auton_Blue_Left_Start_Six_Flag.h"
#include "libIterativeRobot/commands/Auton/Auton_Red_Left_Start_Six_Flag.h"
#include "libIterativeRobot/commands/Auton/Auton_Blue_Right_Start_Six_Flag.h"
#include "libIterativeRobot/commands/Auton/Auton_Red_Right_Start_Six_Flag.h"

Robot*     Robot::instance  = 0;
Base*      Robot::robotBase = 0;
Collector* Robot::collector = 0;
Flipper*    Robot::flipper = 0;
Flywheel*  Robot::flywheel  = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  robotBase = new Base();
  collector = new Collector();
  flipper = new Flipper();
  flywheel  = new Flywheel();

  autonChooser = AutonChooser::getInstance();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);

  libIterativeRobot::JoystickButton* flywheelForwardButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  flywheelForwardButton->whenPressed(new FlywheelForward());
  libIterativeRobot::JoystickButton* flywheelBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  flywheelBackwardsButton->whenPressed(new FlywheelBackwards());

  collectorForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  collectorForwardsButton->whileHeld(new CollectorForward());
  libIterativeRobot::JoystickButton* collectorBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  collectorBackwardsButton->whileHeld(new CollectorBackwards());

  libIterativeRobot::JoystickButton* middleCollectorForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  middleCollectorForwardsButton->whenPressed(new MiddleCollectorForwardTimed(100));

  libIterativeRobot::JoystickButton* middleCollectorBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  //middleCollectorBackwardsButton->whileHeld(new MiddleCollectorBackwards());
  middleCollectorBackwardsButton->whileHeld(new FlipperForward());

  libIterativeRobot::JoystickButton* flipperForwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);
  flipperForwardsButton->whileHeld(new FlipperForward());
  libIterativeRobot::JoystickButton* flipperBackwardsButton = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_B);
  flipperBackwardsButton->whileReleased(new FlipperBackwardTimed(750));

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
  printf("Default autonInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->uninit();

  switch (autonChooser->getAutonChoice()) {
    case 0:
      printf("Running group %d\n", 1);
      autonGroup = new Auton_Blue_Left_Start_Six_Flag();
      break;
    case 1:
      printf("Running group %d\n", 1);
      autonGroup = new Auton_Blue_Right_Start_Six_Flag();
      break;
    case 2:
      printf("Running group %d\n", 2);
      autonGroup = new Auton_Red_Left_Start_Six_Flag();
      break;
    case 3:
      printf("Running group %d\n", 2);
      autonGroup = new Auton_Red_Right_Start_Six_Flag();
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
  printf("Default teleopInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->init();
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  printf("Button state: %d\n", collectorForwardsButton->get());
  //Motor::periodicUpdate();
  //PIDController::loopAll();
}

void Robot::disabledInit() {
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
  autonChooser->uninit();
}

Robot* Robot::getInstance() {
  if (instance == 0) {
    instance = new Robot();
  }
  return instance;
}
