#ifndef _SUBSYSTEMS_ARM_H_
#define _SUBSYSTEMS_ARM_H_

#include "./Subsystem.h"
#include "api.h"

class Arm : public libIterativeRobot::Subsystem {
  private:

  public:
    void initDefaultCommand();
    Arm();
};

#endif // _SUBSYSTEMS_ARM_H_
