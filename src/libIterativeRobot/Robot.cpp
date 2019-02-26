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

using namespace libIterativeRobot;

Robot*     Robot::instance  = 0;
Base*      Robot::robotBase = 0;
Collector* Robot::collector = 0;
MiddleCollector* Robot::middleCollector = 0;
Flipper*   Robot::flipper = 0;
Flywheel*  Robot::flywheel  = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  robotBase = new Base();
  collector = new Collector();
  middleCollector = new MiddleCollector();
  flipper = new Flipper();
  flywheel  = new Flywheel();

  autonChooser = AutonChooser::getInstance();
  autonChooser->setAutonNames(
    {
      "Front Tile Red",
      "Back Tile Red",
      "Front Tile Blue",
      "Back Tile Blue"
    }
  );

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);


  JoystickButton* flywheelForwardButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  flywheelForwardButton->whenPressed(new FlywheelForward());

  JoystickButton* flywheelBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  flywheelBackwardsButton->whenPressed(new FlywheelBackwards());


  JoystickButton* collectorForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  collectorForwardsButton->whileHeld(new CollectorForward());

  JoystickButton* collectorBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  collectorBackwardsButton->whileHeld(new CollectorBackwards());


  JoystickButton* middleCollectorForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  middleCollectorForwardsButton->whileHeld(new MiddleCollectorForward());

  JoystickButton* middleCollectorBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  middleCollectorBackwardsButton->whileHeld(new FlipperForward());
  Command* cancellable = new FlipperBackwardTimed(2000);
  //middleCollectorBackwardsButton->whenReleased(cancellable);
  //middleCollectorBackwardsButton->whenPressed(cancellable, libIterativeRobot::STOP);


  JoystickButton* flipperForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);
  flipperForwardsButton->whileHeld(new FlipperForward());

  //JoystickButton* flipperBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_B);
  //flipperBackwardsButton->whenReleased(new FlipperBackwardTimed(400));


  JoystickButton* toggleButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_Y);
  toggleButton->whenPressed(new BaseToggle());

  JoystickButton* speedToggleButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_A);
  speedToggleButton->whenPressed(new BaseSpeedToggle());

  JoystickButton* autonButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_LEFT);
  autonButton->whenPressed(new Auton_Blue_Left_Start_Six_Flag());

  autonGroup = NULL;
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Starting autonInit() function\n");
  libIterativeRobot::EventScheduler::getInstance()->initialize();
  autonChooser->uninit();

  switch (autonChooser->getAutonChoice()) {
    case 0:
      printf("Running group %d\n", 1);
      autonGroup = new Auton_Blue_Left_Start_Six_Flag();
      break;
    case 1:
      printf("Running group %d\n", 1);
      autonGroup = new Auton_Blue_Left_Start_Six_Flag();
      break;
    case 2:
      printf("Running group %d\n", 2);
      autonGroup = new Auton_Blue_Left_Start_Six_Flag();
      break;
    case 3:
      printf("Running group %d\n", 2);
      autonGroup = new Auton_Blue_Left_Start_Six_Flag();
      break;
  }
  autonGroup->run();

}

void Robot::autonPeriodic() {
  EventScheduler::getInstance()->update();
}

void Robot::teleopInit() {
  printf("Starting teleopInit() function\n");
  EventScheduler::getInstance()->initialize();
  autonChooser->init();
}

void Robot::teleopPeriodic() {
  // Code to run while in teleop mode
  printf("Gyro value: %f\n", robotBase->getGyroValue());
  EventScheduler::getInstance()->update();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  autonChooser->uninit();
}

Robot* Robot::getInstance() {
  if (instance == 0) {
    instance = new Robot();
  }
  return instance;
}
