#pragma once
#include "main.h"
using namespace okapi;
extern Controller master;
extern MotorGroup LeftDrive;
extern MotorGroup RightDrive;
extern MotorGroup Catapult;
extern std::shared_ptr<IMU> imu;
extern std::shared_ptr<ChassisController> chassis;
extern model::Solenoid claw;
extern model::Solenoid wings;