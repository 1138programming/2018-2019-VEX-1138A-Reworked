#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "api.h"
#include "main.h"
#include "RobotBase.h"
#include "commands/CommandGroup.h"
#include "subsystems/Base.h"
#include "subsystems/Collector.h"
#include "subsystems/Flipper.h"
#include "subsystems/Flywheel.h"

#include "events/EventScheduler.h"

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

    // Robot subsystems

    static Base* robotBase;
    static Collector* collector;
    static Flipper* flipper;
    static Flywheel* flywheel;

    static AutonChooser* autonChooser;

    static pros::Controller* mainController;

    // So that we don't leak memory
    libIterativeRobot::CommandGroup* autonGroup;
};


#endif // _ROBOT_H_
