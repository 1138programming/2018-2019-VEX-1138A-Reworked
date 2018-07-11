#ifndef _SUBSYSTEMS_EXAMPLESUBSYSTEM_H_
#define _SUBSYSTEMS_EXAMPLESUBSYSTEM_H_

#include "subsystems/Subsystem.h"

class ExampleSubsystem : public Subsystem {
  public:
    void initDefaultCommand();
    ExampleSubsystem();
};

#endif // _SUBSYSTEMS_EXAMPLESUBSYSTEM_H_
