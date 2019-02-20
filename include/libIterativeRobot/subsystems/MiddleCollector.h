#ifndef _SUBSYSTEMS_MIDDLECOLLECTOR_H_
#define _SUBSYSTEMS_MIDDLECOLLECTOR_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class MiddleCollector : public libIterativeRobot::Subsystem {
  private:
    Motor* middleCollectorMotor;
    pros::ADIUltrasonic* ultrasonic;
    
  public:
    void initDefaultCommand();
    void runMiddleCollector(int velocity);
    int getUltrasonic();
    MiddleCollector();
};

#endif // _SUBSYSTEMS_MiddleCollector_H_
