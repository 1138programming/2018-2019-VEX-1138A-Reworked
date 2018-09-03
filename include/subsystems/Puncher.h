// 2 motors, y-cabled

#ifndef PUNCHER_H
#define PUNCHER_H

#include "main.h"

class Puncher : public Subsystem {
  private:
    static Puncher* instance;
    Motor* puncherMotor;
    Puncher();
  public:
    void initDefaultCommand();
    void move(int speed);
    static Puncher* getInstance();
};

#endif
