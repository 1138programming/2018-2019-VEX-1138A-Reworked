#ifndef _SUBSYSTEMS_ULTRASONIC_H_
#define _SUBSYSTEMS_ULTRASONIC_H_

#include "./Subsystem.h"
#include "api.h"

class Ultrasonic : public libIterativeRobot::Subsystem {
  private:
    pros::ADIUltrasonic* ultrasonic;
  public:
    void initDefaultCommand();
    int getUltrasonic();
    Ultrasonic();
};

#endif // _SUBSYSTEMS_ULTRASONIC_H_
