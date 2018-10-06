#ifndef _SUBSYSTEMS_CLAW_H_
#define _SUBSYSTEMS_CLAW_H_

#include "./Subsystem.h"
#include "api.h"

class Claw : public libIterativeRobot::Subsystem {
  private:

  public:
    void initDefaultCommand();
    Claw();
};

#endif // _SUBSYSTEMS_CLAW_H_
