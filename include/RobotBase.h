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
    void doOneCycle();
  protected:
    /**
      * This runs once when the robot starts up.
      */
    virtual void robotInit();

    /**
      * This runs once each time the autonomous period begins.
      */
    virtual void autonInit();

    /**
      * This runs in a loop during the autonomous period.
      */
    virtual void autonPeriodic();

    /**
      * This runs once each time the teleoperated period begins.
      */
    virtual void teleopInit();

    /**
      * This runs in a loop during the teleoperated period.
      */
    virtual void teleopPeriodic();

    /**
      * This runs once each time the robot is disabled.
      */
    virtual void disabledInit();

    /**
      * This runs in a loop whenever the robot is disabled.
      */
    virtual void disabledPeriodic();

  public:
    RobotBase();

    /**
      * Run the robot.
      *
      * This should be called with the main robot class as the template argument.
      * For example, if your robot is named `ExampleRobot`, you would call
      * it with `RobotBase::runRobot<ExampleRobot>()`
      */
    template <class RobotMain> static void runRobot() {
      // Just saying, if this doesn't work, try using the reinterepret cast on the method instead, instead of its pointer
      taskCreate(reinterpret_cast<void (*)(void*)>(&_privateRunRobot<RobotMain>), TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
    };
};

#endif // _ROBOTBASE_H_
