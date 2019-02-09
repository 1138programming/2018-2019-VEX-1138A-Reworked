#ifndef _SUBSYSTEMS_COLLECTOR_H_
#define _SUBSYSTEMS_COLLECTOR_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Collector : public libIterativeRobot::Subsystem {
  private:
    Motor* frontCollectorMotor;
    Motor* middleCollectorMotor;
    pros::ADIUltrasonic* ultrasonic;
    
  public:
    void initDefaultCommand();
    void runFrontCollector(int velocity);
    void runMiddleCollector(int velocity);
    int getUltrasonic();
    Collector();
};

#endif // _SUBSYSTEMS_COLLECTOR_H_
