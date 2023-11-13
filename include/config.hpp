#pragma once
#include "main.h"
using namespace okapi;
extern Controller master;
extern MotorGroup LeftDrive;
extern MotorGroup RightDrive;
extern Motor Catapult;
extern Motor Intake;
extern std::shared_ptr<IMU> Imu;
extern std::shared_ptr<ChassisController> chassis;
extern model::Solenoid wings1;
extern model::Solenoid wings2;