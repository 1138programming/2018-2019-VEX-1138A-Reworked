#include "libIterativeRobot/Robot.h"
#include "libIterativeRobot/events/EventScheduler.h"
#include "libIterativeRobot/events/JoystickButton.h"
#include "libIterativeRobot/events/JoystickChannel.h"

Robot* Robot::instance = 0;

Robot::Robot() {
  printf("Overridden robot constructor!\n");
  // Initialize any subsystems
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

Robot* Robot::getInstance() {
    if (instance == NULL) {
        instance = new Robot();
    }
    return instance;
}
