#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "main.h"
#include "RobotBase.h"
#include "subsystems/ExampleSubsystem.h"

class Robot : public libIterativeRobot::RobotBase {
  private:
    static Robot* instance;
  protected:
    void robotInit();
    void autonInit();
    void autonPeriodic();
    void teleopInit();
    void teleopPeriodic();
    void disabledInit();
    void disabledPeriodic();
  public:
    Robot();
    static Robot* getInstance();

    static ExampleSubsystem* exampleSubsystem;
};


#endif // _ROBOT_H_
