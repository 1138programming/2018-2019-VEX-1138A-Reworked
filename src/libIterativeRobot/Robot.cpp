#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

#include "libIterativeRobot/commands/StopBase.h"
#include "libIterativeRobot/commands/StopArm.h"
#include "libIterativeRobot/commands/StopClaw.h"
#include "libIterativeRobot/commands/DriveWithJoy.h"
#include "libIterativeRobot/commands/ArmControl.h"
#include "libIterativeRobot/commands/ClawControl.h"
#include "libIterativeRobot/commands/MoveArmFor.h"
#include "libIterativeRobot/commands/MoveArmTo.h"

Base*  Robot::base = 0;
Arm*   Robot::arm = 0;
Claw*  Robot::claw = 0;

pros::Controller* Robot::mainController = 0;
pros::Controller* Robot::partnerController = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
  base = new Base();
  arm  = new Arm();
  claw = new Claw();

  mainController = new pros::Controller(pros::E_CONTROLLER_MASTER);
  partnerController = new pros::Controller(pros::E_CONTROLLER_PARTNER);

  // Define buttons and channels
  libIterativeRobot::JoystickChannel* RightY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  libIterativeRobot::JoystickChannel* LeftY = new libIterativeRobot::JoystickChannel(mainController, pros::E_CONTROLLER_ANALOG_LEFT_Y);
  libIterativeRobot::JoystickButton* ArmUp = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R1);
  libIterativeRobot::JoystickButton* ArmDown = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_R2);
  libIterativeRobot::JoystickButton* ClawOpen = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L1);
  libIterativeRobot::JoystickButton* ClawClose = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_L2);
  libIterativeRobot::JoystickButton* ArmToStart = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_DOWN);
  libIterativeRobot::JoystickButton* ArmToHorizontal = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_RIGHT);
  libIterativeRobot::JoystickButton* ArmToTop = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_UP);
  libIterativeRobot::JoystickButton* ArmToBack = new libIterativeRobot::JoystickButton(mainController, pros::E_CONTROLLER_DIGITAL_LEFT);

  // Add commands to be run to buttons
  DriveWithJoy* driveCommand = new DriveWithJoy();
  RightY->whilePastThreshold(driveCommand);
  LeftY->whilePastThreshold(driveCommand);

  ArmUp->whileHeld(new ArmControl(true));
  ArmDown->whileHeld(new ArmControl(false));

  ClawOpen->whileHeld(new ClawControl(true));
  ClawClose->whileHeld(new ClawControl(false));

  ArmToStart->whenPressed(new MoveArmTo(0));
  ArmToHorizontal->whenPressed(new MoveArmTo(680));
  ArmToTop->whenPressed(new MoveArmTo(1520));
  ArmToBack->whenPressed(new MoveArmTo(2360));
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
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::teleopInit() {
  printf("Default teleopInit() function\n");
}

void Robot::teleopPeriodic() {
  //printf("Default teleopPeriodic() function\n");
  libIterativeRobot::EventScheduler::getInstance()->update();
  Motor::periodicUpdate();
  PIDController::loopAll();
}

void Robot::disabledInit() {
  printf("Default disabledInit() function\n");
}

void Robot::disabledPeriodic() {
  //printf("Default disabledPeriodic() function\n");
}
