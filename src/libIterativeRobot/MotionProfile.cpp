#include "libIterativeRobot/MotionProfile.h"
#include "libIterativeRobot/Ways.h"

MotionProfile::MotionProfile(std::initializer_list<okapi::Point> points) {
    this->points = points;
}

bool MotionProfile::canRun() {
    return true; // This is the default value anyways, so this method can be removed
}

void MotionProfile::initialize() {
    profileController.generatePath(points, "A");
    profileController.setTarget("A");
}

void MotionProfile::execute() {
}

bool MotionProfile::isFinished() {
    return profileController.isSettled();
}

void MotionProfile::end() {
}

void MotionProfile::interrupted() {
}
