#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/FlywheelCommands/FlywheelForward.h"
#include "libIterativeRobot/commands/FlywheelCommands/FlywheelBackwards.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorForward.h"
#include "libIterativeRobot/commands/CollectorCommands/CollectorBackwards.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerForward.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerBackwards.h"
#include "libIterativeRobot/commands/IndexerCommands/IndexerForwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperForward.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwards.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperBackwardTimed.h"
#include "libIterativeRobot/commands/FlipperCommands/FlipperTo.h"

#include "libIterativeRobot/commands/Auton/Auton_Blue_Left_Start_Six_Flag.h"
#include "libIterativeRobot/commands/Auton/Auton_Red_Left_Start_Six_Flag.h"
#include "libIterativeRobot/commands/Auton/Auton_Blue_Right_Start_Six_Flag.h"
#include "libIterativeRobot/commands/Auton/Auton_Red_Right_Start_Six_Flag.h"

#include "libIterativeRobot/commands/BaseCommands/ToggleBrake.h"

#include "libIterativeRobot/commands/MiscCommands/DelayCommand.h"
#include "libIterativeRobot/commands/MiscCommands/CollectorAndIndexer.h"
#include "libIterativeRobot/commands/MiscCommands/ShootAndLoad.h"

#include "libIterativeRobot/commands/Auton/SkillsAuton.h"

using namespace libIterativeRobot;

Robot*     Robot::instance  = 0;
Base*      Robot::robotBase = 0;
Collector* Robot::collector = 0;
Indexer* Robot::indexer = 0;
Flipper*   Robot::flipper = 0;
Flywheel*  Robot::flywheel  = 0;

AutonChooser* Robot::autonChooser = 0;

pros::Controller* Robot::mainController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initializing subsystems
  robotBase = new Base();
  collector = new Collector();
  indexer = new Indexer();
  flipper = new Flipper();
  flywheel  = new Flywheel();

  // Set autons available to be chosen
  autonChooser = AutonChooser::getInstance();
  autonChooser->setAutonNames(
    {
      "Front Tile Red",
      "Back Tile Red",
      "Front Tile Blue",
      "Back Tile Blue",
      "Skills"
    }
  );

  // Initializing controller
  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);

  // Initializing joysticks and buttons
  // JoystickButton* flywheelForwardButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  // flywheelForwardButton->whenPressed(new FlywheelForward());

  JoystickButton* flywheelBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  flywheelBackwardsButton->whenPressed(new FlywheelBackwards());


  JoystickButton* collectorForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  collectorForwardsButton->whileHeld(new CollectorAndIndexer());
  //collectorForwardsButton->whileHeld(new CollectorForward());

  JoystickButton* collectorBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  collectorBackwardsButton->whileHeld(new CollectorBackwards());


  JoystickButton* indexerForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  //indexerForwardsButton->whileHeld(new IndexerForward());
  //indexerForwardsButton->whileHeld(new CollectorForward());
  indexerForwardsButton->whenPressed(new ShootAndLoad());

  // JoystickButton* flipperForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  // flipperForwardsButton->whileHeld(new FlipperForward());
  //Command* cancellable = new FlipperBackwardTimed(2000);
  //flipperBackwardsButton->whenReleased(cancellable);
  //flipperBackwardsButton->whenPressed(cancellable, libIterativeRobot::STOP);

  JoystickButton* toggleBrakeButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  toggleBrakeButton->whenPressed(new ToggleBrake(true));
  toggleBrakeButton->whenReleased(new ToggleBrake(false));

  JoystickButton* flipperForwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_X);
  flipperForwardsButton->whileHeld(new FlipperForward());

  JoystickButton* flipperBackwardsButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_Y);
  flipperBackwardsButton->whileHeld(new FlipperBackwards());

  //JoystickButton* autonButton = new JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_LEFT);
  //autonButton->whenPressed(new Auton_Blue_Left_Start_Six_Flag());

  autonGroup = NULL;
}

void Robot::robotInit() {
  printf("Robot created.\n");
}

void Robot::autonInit() {
  printf("Starting autonInit() function\n");
  Motor::resetEncoders();
  autonChooser->uninit();

  //bool isSkills = true;

  /*if (isSkills) {
    autonGroup = new SkillsAuton();
  } else {*/
  //if () {
    switch (autonChooser->getAutonChoice()) {
      case 0:
        printf("Running group %d\n", 1);
        autonGroup = new Auton_Red_Left_Start_Six_Flag();
        break;
      case 1:
        printf("Running group %d\n", 1);
        autonGroup = new Auton_Red_Right_Start_Six_Flag();
        break;
      case 2:
        printf("Running group %d\n", 2);
        autonGroup = new Auton_Blue_Left_Start_Six_Flag();
        break;
      case 3:
        printf("Running group %d\n", 2);
        autonGroup = new Auton_Blue_Right_Start_Six_Flag();
        break;
      case 4:
        printf("Running skills group\n");
        autonGroup = new SkillsAuton();
        break;
    }
  //}
  autonGroup->run();
  //Command* delay = new DelayCommand(1000);
  //delay->run();
}

void Robot::autonPeriodic() {
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::teleopInit() {
  //printf("Starting teleopInit() function\n");
  Motor::resetEncoders();
  autonChooser->init();
}

void Robot::teleopPeriodic() {
  // Code to run while in teleop mode
  //printf("Gyro value: %f\n", robotBase->getGyroValue());
  //printf("Left encoder value is %f, right encoder value is %f\n", robotBase->getLeftEncoderValue(), robotBase->getRightEncoderValue());
  Motor::periodicUpdate();
  PIDController::loopAll();
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
