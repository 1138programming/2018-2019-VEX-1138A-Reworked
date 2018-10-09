#include "main.h"
//#include "commands/StopClaw.h"

Claw* Claw::instance = 0;

Claw::Claw() {
  // Get claw motors
  clawMotor = Motor::getMotor(clawPort);
}

void Claw::initDefaultCommand() {
  //setDefaultCommand(new StopClaw());
}

/**
 * Move the claw
 * @param speed - speed of the speed side
 * @param right - speed of the right side
 */
void Claw::move(int speed) {
  clawMotor->setSpeed(speed);
}

Claw* Claw::getInstance() {
    if (instance == 0) {
      instance = new Claw();
    }

    return instance;
}
