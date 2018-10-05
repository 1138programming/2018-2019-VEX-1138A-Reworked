#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "main.h"
#include "RobotBase.h"
#include "subsystems/Base.h"

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

    static Base* robotBase;
};


#endif // _ROBOT_H_
