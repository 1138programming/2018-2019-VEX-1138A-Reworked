#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "./Subsystem.h"
#include "api.h"

class Base : public libIterativeRobot::Subsystem {
  private:

  public:
    void initDefaultCommand();
    Base();
};

#endif // _SUBSYSTEMS_BASE_H_
