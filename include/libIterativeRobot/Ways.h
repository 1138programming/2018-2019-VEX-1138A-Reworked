#ifndef WAYS_H
#define WAYS_H

#include "main.h"
#include "Constants.h"
#include "okapi/api.hpp"

using namespace okapi;

constexpr double maxVel = 1;
constexpr double maxAccel = 2;
constexpr double maxJerk = 10;
constexpr double dt = 0.001;

auto myChassis = ChassisControllerFactory::create(
    {leftFrontBaseMotorPort, leftBackBaseMotorPort},
    {rightFrontBaseMotorPort, rightBackBaseMotorPort},
    AbstractMotor::gearset::red,
    {4_in, 12.5_in}
);

auto profileController = AsyncControllerFactory::motionProfile(
    maxVel,
    maxAccel,
    maxJerk,
    myChassis
);

std::initializer_list<okapi::Point> TEST_PROFILE = {
    Point{0_ft, 0_ft, 0_deg},
    Point{2_ft, 0_ft, 0_deg},
};

#endif