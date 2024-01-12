#pragma once
#include "main.h"
using namespace okapi;
extern pros::Controller master;
extern MotorGroup LeftDrive;
extern MotorGroup RightDrive;
extern MotorGroup Flywheel;
extern std::shared_ptr<IMU> Imu;
extern std::shared_ptr<ChassisController> chassis;
extern model::Solenoid lift;
extern model::Solenoid wingsL;
extern model::Solenoid wingsR;