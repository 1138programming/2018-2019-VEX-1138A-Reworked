#ifndef _ROBOTBASE_H_
#define _ROBOTBASE_H_

#include "main.h"

class RobotBase {
  private:
    enum class RobotState {
      None,
      Auton,
      Teleop,
      Disabled,
    };
    RobotState lastState = RobotState::None;
    template<class RobotMain> static void _privateRunRobot() {
      RobotMain* robotInstance = RobotMain::getInstance();
      while (true) {
        robotInstance->doOneCycle();
      }
    };
  protected:
    virtual void robotInit();
    virtual void autonInit();
    virtual void autonPeriodic();
    virtual void teleopInit();
    virtual void teleopPeriodic();
    virtual void disabledInit();
    virtual void disabledPeriodic();
  public:
    void doOneCycle();
    RobotBase();

    template <class RobotMain> static void runRobot() {
      // Just saying, if this doesn't work, try using the reinterepret cast on the method instead, instead of its pointer
      taskCreate(reinterpret_cast<void (*)(void*)>(&_privateRunRobot<RobotMain>), TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
    };
};

#endif // _ROBOTBASE_H_
