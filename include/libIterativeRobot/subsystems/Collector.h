#ifndef _SUBSYSTEMS_COLLECTOR_H_
#define _SUBSYSTEMS_COLLECTOR_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Collector : public libIterativeRobot::Subsystem {
  private:
    Motor* frontCollectorMotor;
    
  public:
    void initDefaultCommand();
    void runFrontCollector(int velocity);
    Collector();
};

#endif // _SUBSYSTEMS_COLLECTOR_H_
