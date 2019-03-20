#ifndef MOTIONPROFILE_H
#define MOTIONPROFILE_H

#include "libIterativeRobot/Ways.h"
#include "libIterativeRobot/commands/Command.h"

using namespace libIterativeRobot;

class MotionProfile : public libIterativeRobot::Command {
    private:
        std::initializer_list<okapi::Point> points;
    public:
        bool canRun();
        void initialize();
        void execute();
        bool isFinished();
        void end();
        void interrupted();
        MotionProfile(std::initializer_list<okapi::Point> points);
};

#endif
