#ifndef _SUBSYSTEMS_INDEXER_H_
#define _SUBSYSTEMS_INDEXER_H_

#include "./Subsystem.h"
#include "api.h"
#include "abstractBaseClasses/Motor.h"

class Indexer : public libIterativeRobot::Subsystem {
  private:
    Motor* indexerMotor;
    pros::ADIUltrasonic* ultrasonic;

  public:
    void initDefaultCommand();
    void runIndexer(int velocity);
    double getEncoderValue();
    int getUltrasonic();
    Indexer();
};

#endif // _SUBSYSTEMS_INDEXER_H_
