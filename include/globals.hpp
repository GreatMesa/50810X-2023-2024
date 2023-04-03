#pragma once
#include "main.h"
//Controller
extern Controller master;
//Motors
extern Motor Drive1;
extern Motor Drive2;
extern Motor Drive3;
extern Motor Drive4;
extern Motor Drive5;
extern Motor Drive6;
extern MotorGroup LeftDrive;
extern MotorGroup RightDrive;

//Sensors
extern IMU imu;
extern ADIEncoder Center;
extern std::shared_ptr<ChassisController> chassis;

extern std::shared_ptr<IterativePosPIDController> turnPID;
