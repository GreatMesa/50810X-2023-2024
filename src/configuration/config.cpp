#include "main.h"
using namespace okapi;
//Controller
okapi::Controller master(ControllerId::master);
//Motors
Motor LeftFront(8,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LeftMiddle(9,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LeftBack(10,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RightFront(3,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RightMiddle(2,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RightBack(1,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor Intake(4,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor Catapult(7,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
//Motor Groups
MotorGroup LeftDrive({LeftFront, LeftMiddle, LeftBack});
MotorGroup RightDrive({RightFront, RightMiddle, RightBack});
//Chassis
std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(LeftDrive, RightDrive)
    .withDimensions({AbstractMotor::gearset::blue, 1.333}, {{2.75_in,12_in}, imev5BlueTPR})
    .build();
//Sensors
std::shared_ptr<okapi::IMU> Imu(new IMU(5));
//Solenoid
model::Solenoid wings1('G',false);
model::Solenoid wings2('H',false);

