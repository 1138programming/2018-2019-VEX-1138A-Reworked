// 1 motor

#ifndef INTAKE_H
#define INTAKE_H

#include "main.h"

class Intake : public Subsystem {
  private:
    static Intake* instance;
    Motor* intakeMotor;
    Intake();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Intake* getInstance();
};

#endif
